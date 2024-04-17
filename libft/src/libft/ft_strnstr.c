/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quincy <quincy@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 14:07:20 by quincy        #+#    #+#                 */
/*   Updated: 2024/03/12 19:06:04 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	i = 0;
	needle_len = (size_t) ft_strlen(needle);
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0] && len - i >= needle_len)
		{
			if (!ft_strncmp(&haystack[i], needle, needle_len))
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
