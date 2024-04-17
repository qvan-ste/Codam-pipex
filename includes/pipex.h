/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/24 19:22:40 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/13 18:14:13 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

int		exec_childs(char *envp[], char**argv_3d[],
			int num_of_cmd, char **paths);
void	exec_child_a(char *envp[], char **argv_3d[], int fd[], char *path);
void	exec_child_b(char *envp[], char **argv_3d[], int fd[], char *path);
char	*check_path(char *cmd_file, char *path_list[]);
char	**get_path_list(char *envp[]);
char	*get_path(char *envp[], char *cmd);
char	**create_path_array(char *envp[], char **argv_3d[], int num_of_cmd);
int		slash_len(char *s);
char	*remove_multi_slash(char *s);
char	**split_parentheses(char *s);
void	free_arg_3d_and_paths(char **argv_3d[], char *paths[], int argc);
char	***create_argv_3d(char *argv[], int argc);
int		unix_error(char **paths, char**argv_3d[], int i, int num_of_cmd);
int		wait_and_close(int fd[], pid_t pid);
void	free_linked_list(t_list *head);
char	**make_arg_array(t_list *head);
char	*join_args(char *splitted, char *arg);
int		join_quotes(char **splitted, t_list *head);

#endif