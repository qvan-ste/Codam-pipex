/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_basic_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 15:32:55 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/17 13:43:16 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_fd.h"
#include "../../includes/libft.h"

int	print_char_fd(char c, const int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	print_str_fd(char *s, const int fd)
{
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	print_percent_fd(const int fd)
{
	write(fd, "%", 1);
	return (1);
}
