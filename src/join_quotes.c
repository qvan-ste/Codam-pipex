/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   join_quotes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 11:18:31 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/13 17:53:50 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_linked_list(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

char	**make_arg_array(t_list *head)
{
	int		i;
	char	**ret;

	i = 0;
	ret = malloc((sizeof (char **) * (ft_lstsize(head) + 1)));
	if (!ret)
		return (NULL);
	while (head)
	{
		ret[i] = head -> content;
		head = head -> next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char	*join_args(char *splitted, char *arg)
{
	char	*tmp;

	tmp = arg;
	arg = ft_strjoin(tmp, " ");
	free (tmp);
	if (!arg)
		return (NULL);
	tmp = arg;
	arg = ft_strjoin(tmp, splitted);
	free(tmp);
	if (!arg)
		return (NULL);
	return (arg);
}

int	join_quotes(char **splitted, t_list *head)
{
	int		i;
	char	*arg;
	t_list	*node;

	i = 1;
	if (splitted[i])
		arg = ft_strdup(splitted[i] + 1);
	while (splitted[i])
	{
		if (!arg)
			return (1);
		while (splitted[i + 1])
		{
			arg = join_args(splitted[i++ + 1], arg);
			if (!arg)
				return (1);
		}
		node = ft_lstnew(arg);
		if (!node)
			return (1);
		ft_lstadd_back(&head, node);
		i++;
	}
	arg[ft_strlen(arg) - 1] = '\0';
	return (0);
}
