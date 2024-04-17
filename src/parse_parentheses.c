/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_parentheses.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 17:20:10 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/15 13:10:04 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	slash_len(char *s)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == '\\' && (s[i + 1] == '\\' || s[i + 1] == '"'
				|| s[i + 1] == '$' || s[i + 1] == '\''))
			i++;
		i++;
		n++;
	}
	return (n);
}

char	*remove_multi_slash(char *s)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = ft_calloc (slash_len(s) + 1, sizeof (char));
	if (!ret)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\\' && (s[i + 1] == '\\' || s[i + 1] == '"'
				|| s[i + 1] == '$' || s[i + 1] == '\''))
			i++;
		ret[j++] = s[i];
		i++;
	}
	ret[j] = '\0';
	return (ret);
}

char	**split_parentheses(char *s)
{
	char	**splitted;
	t_list	*head;
	char	*no_slash;
	int		i;

	i = 0;
	no_slash = remove_multi_slash(s);
	if (!no_slash)
		return (NULL);
	splitted = ft_split(no_slash, ' ');
	free (no_slash);
	if (!splitted)
		return (NULL);
	head = ft_lstnew(ft_strdup(splitted[0]));
	if (!head || !head -> content)
		return (ft_free_array(splitted), free_linked_list(head), NULL);
	if (join_quotes(splitted, head))
		return (ft_free_array(splitted), free_linked_list(head), NULL);
	ft_free_array(splitted);
	splitted = make_arg_array(head);
	if (!splitted)
		return (free_linked_list(head), NULL);
	free_linked_list(head);
	return (splitted);
}
