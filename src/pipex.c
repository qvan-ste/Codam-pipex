/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 19:22:44 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/13 18:00:28 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec_child_a(char *envp[], char **argv_3d[], int fd[], char *path)
{
	int	infile;

	infile = open(*argv_3d[1], O_RDONLY);
	if (infile < 0)
		exit(1);
	dup2(infile, STDIN_FILENO);
	dup2(fd[STDOUT_FILENO], STDOUT_FILENO);
	close(fd[STDIN_FILENO]);
	close(fd[STDOUT_FILENO]);
	close(infile);
	execve(path, argv_3d[2], envp);
	exit(1);
}

void	exec_child_b(char *envp[], char **argv_3d[], int fd[], char *path)
{
	int	outfile;

	outfile = open(*argv_3d[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (outfile < 0)
		exit(1);
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[STDIN_FILENO], STDIN_FILENO);
	close(fd[STDOUT_FILENO]);
	close(fd[STDIN_FILENO]);
	close(outfile);
	execve(path, argv_3d[3], envp);
	exit(1);
}

int	exec_childs(char *envp[], char**argv_3d[], int num_of_cmd, char **paths)
{
	pid_t	pid;
	int		fd[2];
	int		i;
	int		status;

	i = 0;
	if (pipe(fd) < 0)
		return (1);
	while (i < num_of_cmd)
	{
		unix_error(paths, argv_3d, i, num_of_cmd);
		pid = fork();
		if (pid < 0)
			return (1);
		if (!pid)
		{
			if (i == 0)
				exec_child_a(envp, argv_3d, fd, paths[i]);
			exec_child_b(envp, argv_3d, fd, paths[i]);
		}
		i++;
	}
	status = wait_and_close(fd, pid);
	return (status);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	***argv_3d;
	char	**paths;
	int		status;

	if (argc != 5)
		exit(1);
	argv_3d = create_argv_3d(argv, argc);
	if (!argv_3d)
		exit(1);
	paths = create_path_array(envp, argv_3d, argc - 3);
	if (!paths)
	{
		free_arg_3d_and_paths(argv_3d, paths, argc);
		exit(1);
	}
	status = exec_childs(envp, argv_3d, argc - 3, paths);
	free_arg_3d_and_paths(argv_3d, paths, argc);
	exit(status);
}
