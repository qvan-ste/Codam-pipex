/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 16:52:41 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/13 14:21:39 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n)
	{
		*(char *)s = '\0';
		s++;
		n--;
	}
}
