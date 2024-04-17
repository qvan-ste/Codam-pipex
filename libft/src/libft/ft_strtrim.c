/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 14:09:47 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/12 19:06:09 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	is_in_arr(const char c, char const *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*trimmed;

	if (!s1 || !set)
		return ((char *) s1);
	start = 0;
	end = ft_strlen(s1) - 1;
	i = 0;
	while (is_in_arr(s1[start], set))
		start++;
	if (start == (int) ft_strlen(s1))
		return (ft_strdup(""));
	while (is_in_arr(s1[end], set))
		end--;
	trimmed = malloc(end * sizeof(const char) - start * sizeof(const char) + 2);
	if (!trimmed)
		return (NULL);
	while (start <= end)
		trimmed[i++] = s1[start++];
	trimmed[i] = '\0';
	return (trimmed);
}
