/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_ptr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 15:00:35 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/17 13:47:05 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_fd.h"
#include "../../includes/libft.h"

static void	write_ptr_fd(intptr_t ptr, const int fd)
{
	const char	*digits = "0123456789abcdef";
	const char	*prefix = "0x";
	char		c;

	if (!(ptr / 16))
		write(fd, prefix, 2);
	if (ptr > 15)
		write_ptr_fd((ptr / 16), fd);
	c = digits[ptr % 16];
	write(fd, &c, 1);
}

int	print_ptr_fd(uintptr_t ptr, const int fd)
{
	if (!ptr)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	write_ptr_fd(ptr, fd);
	return (ft_hexlen(ptr) + 2);
}
