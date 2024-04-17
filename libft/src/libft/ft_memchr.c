/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: quincy <quincy@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 22:10:32 by quincy        #+#    #+#                 */
/*   Updated: 2024/03/13 14:29:50 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*char_s;
	unsigned char	char_c;

	i = 0;
	char_s = (unsigned char *)s;
	char_c = (unsigned char)c;
	while (i < n)
	{
		if (char_s[i] == char_c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
