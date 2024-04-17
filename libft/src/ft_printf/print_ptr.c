/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_ptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 15:00:35 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/13 14:53:56 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"

static void	write_ptr(uintptr_t ptr)
{
	const char	*digits = "0123456789abcdef";
	const char	*prefix = "0x";
	char		c;

	if (!(ptr / 16))
		write(1, prefix, 2);
	if (ptr > 15)
		write_ptr(ptr / 16);
	c = digits[ptr % 16];
	write(1, &c, 1);
}

int	print_ptr(uintptr_t ptr)
{
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write_ptr(ptr);
	return (ft_hexlen(ptr) + 2);
}
