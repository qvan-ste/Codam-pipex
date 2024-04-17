/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 19:49:04 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/12 19:05:23 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	n_splits(char const *s, char c)
{
	int	i;
	int	splits;

	i = 0;
	splits = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			splits++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (splits);
}

static char	**free_arr(char **split_arr, int n)
{
	while (n >= 0)
	{
		free(split_arr[n]);
		n--;
	}
	free(split_arr);
	return (0);
}

static void	init_vars(int *i, int *start, int *n)
{
	*i = 0;
	*start = 0;
	*n = 0;
}

static void	skip_i(char const *s, int *i, char c)
{
	while (s[*i] && s[*i] != c)
		*i = *i + 1;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		n;
	char	**split_arr;

	init_vars(&i, &start, &n);
	split_arr = ft_calloc((n_splits(s, c) + 1), sizeof(char *));
	if (!split_arr)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			skip_i(s, &i, c);
			split_arr[n] = ft_substr(s, start, i - start);
			if (!split_arr[n])
				return (free_arr(split_arr, n));
			n++;
		}
		else
			i++;
	}
	split_arr[n] = NULL;
	return (split_arr);
}
