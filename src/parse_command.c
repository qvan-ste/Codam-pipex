/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_command.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 19:47:37 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/13 18:11:45 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*check_path(char *cmd_file, char *path_list[])
{
	char	*path;
	int		i;

	i = 0;
	while (path_list[i])
	{
		path = ft_strjoin(path_list[i], cmd_file);
		if (!path)
			return (NULL);
		if (!access(path, F_OK | X_OK))
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	**get_path_list(char *envp[])
{
	char	**path_list;

	while (envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
			break ;
		envp++;
	}
	if (!*envp)
		return (NULL);
	path_list = ft_split(*envp + 5, ':');
	if (!path_list)
		return (NULL);
	return (path_list);
}

char	*get_path(char *envp[], char *cmd)
{
	char	**path_list;
	char	*path;
	char	*cmd_file;

	if ((cmd[0] == '/' || cmd[0] == '.') && !access(cmd, F_OK))
		return (ft_strdup(cmd));
	cmd_file = ft_strjoin("/", cmd);
	if (!cmd_file)
		return (NULL);
	path_list = get_path_list(envp);
	if (!path_list)
	{
		free(cmd_file);
		return (NULL);
	}
	path = check_path(cmd_file, path_list);
	free(cmd_file);
	ft_free_array(path_list);
	return (path);
}

char	**create_path_array(char *envp[], char **argv_3d[], int num_of_cmd)
{
	char	**path_array;
	int		i;

	i = 0;
	path_array = malloc(sizeof(char *) * (num_of_cmd));
	if (!path_array)
		return (NULL);
	while (i < num_of_cmd)
	{
		path_array[i] = get_path(envp, argv_3d[i + 2][0]);
		i++;
	}
	return (path_array);
}
