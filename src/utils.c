/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 19:49:04 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/18 14:11:59 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <errno.h>
#include <string.h>

void	free_arg_3d_and_paths(char **argv_3d[], char *paths[], int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		ft_free_array(argv_3d[i]);
		i++;
	}
	free(argv_3d);
	i = 0;
	while (i < argc - 3)
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

char	***create_argv_3d(char *argv[], int argc)
{
	char	***argv_3d;
	int		i;

	i = 0;
	argv_3d = malloc(sizeof(char **) * (argc));
	while (argv[i])
	{
		if (ft_strchr(argv[i], '\'') || ft_strchr(argv[i], '"'))
			argv_3d[i] = split_parentheses(argv[i]);
		else
			argv_3d[i] = ft_split(argv[i], ' ');
		if (!argv_3d[i])
		{
			i = 0;
			while (argv_3d[i])
			{
				ft_free_array(argv_3d[i]);
				i++;
			}
			free(argv_3d);
			return (NULL);
		}
		i++;
	}
	return (argv_3d);
}

int	unix_error(char **paths, char**argv_3d[], int i, int num_of_cmd)
{
	if (access(*argv_3d[1], R_OK) && i == 0)
		ft_printf_fd(STDERR_FILENO, "%s: %s: %s\n",
			*argv_3d[0] + 2, strerror(errno), *argv_3d[1]);
	else if (!access(*argv_3d[num_of_cmd + 2], F_OK)
		&& access(*argv_3d[num_of_cmd + 2], W_OK)
		&& i == num_of_cmd - 1)
		ft_printf_fd(STDERR_FILENO, "%s: %s: %s\n",
			*argv_3d[0] + 2, strerror(errno), *argv_3d[num_of_cmd + 2]);
	else if (!paths[i])
		ft_printf_fd(STDERR_FILENO, "%s: Command not found: %s\n",
			*argv_3d[0] + 2, *argv_3d[2 + i]);
	else if (access(paths[i], X_OK))
		ft_printf_fd(STDERR_FILENO, "%s: %s: %s\n",
			*argv_3d[0] + 2, strerror(errno), *argv_3d[2 + i]);
	return (0);
}

int	wait_and_close(int fd[], pid_t pid)
{
	int	status;

	status = 1;
	close(fd[STDOUT_FILENO]);
	close(fd[STDIN_FILENO]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	return (status);
}
