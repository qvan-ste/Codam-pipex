/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 17:54:03 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/12 19:05:04 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	reverse_copy_str(char *char_dest, const char *char_src, size_t len)
{
	while (len)
	{
		char_dest[len - 1] = char_src[len - 1];
		len--;
	}
}

static void	copy_str(char *char_dest, const char *char_src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		char_dest[i] = char_src[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*char_dest;
	const char	*char_src;

	char_dest = (char *)dest;
	char_src = (const char *)src;
	if (!dest && !src)
		return (dest);
	if (src < dest)
		reverse_copy_str(char_dest, char_src, len);
	else
		copy_str(char_dest, char_src, len);
	return (dest);
}
