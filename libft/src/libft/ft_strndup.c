/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/22 12:12:34 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/13 13:15:34 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*s_dupe;

	i = 0;
	if (n >= ft_strlen(s))
		return (ft_strdup(s));
	s_dupe = malloc((sizeof(char) * n) + 1);
	if (!s_dupe)
		return (NULL);
	while (s[i] && i < n)
	{
		s_dupe[i] = s[i];
		i++;
	}
	s_dupe[i] = '\0';
	return (s_dupe);
}
