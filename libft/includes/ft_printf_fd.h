/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_fd.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 17:49:45 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/17 13:42:46 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H
# include <unistd.h>
# include <stdint.h>

int		print_char_fd(char c, int fd);
int		print_str_fd(char *s, int fd);
int		print_percent_fd(int fd);
int		print_hex_upper_fd(unsigned int n, int fd);
int		print_hex_lower_fd(unsigned int n, int fd);
int		print_num_fd(int n, int fd);
int		print_unsigned_fd(long n, int fd);
int		print_ptr_fd(uintptr_t ptr, int fd);

#endif
