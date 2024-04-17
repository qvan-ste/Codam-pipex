/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 17:49:45 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/13 15:53:14 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdint.h>

int		print_char(char c);
int		print_str(char *s);
int		print_percent(void);
int		print_hex_upper(unsigned int n);
int		print_hex_lower(unsigned int n);
int		print_num(int n);
int		print_unsigned(long n);
int		print_ptr(uintptr_t ptr);

#endif
