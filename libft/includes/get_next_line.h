/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 11:49:14 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/13 15:29:21 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*clean_ret(char *full_ret, char **buf, int *error);
char	*save_buf(char *buf, int *error);
char	*read_and_append(int fd, char *buf, char **ret);

#endif
