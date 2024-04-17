/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_num_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 15:36:20 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/17 14:01:48 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <limits.h>

int	print_num_fd(int n, const int fd)
{
	ft_putnbr_fd(n, fd);
	return (ft_intlen(n) + (n < 0));
}

int	print_unsigned_fd(long n, const int fd)
{
	if (n < 0)
		n = UINT_MAX - -n;
	ft_putnbr_fd(n, fd);
	return (ft_intlen(n));
}
