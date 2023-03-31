/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:44:32 by bverdeci          #+#    #+#             */
/*   Updated: 2023/03/31 12:39:50 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	ft_normalize(t_list *s)
{
	int		index;
	t_list	*tmp;
	t_list	*curr;

	curr = s;
	while (curr != NULL)
	{
		index = ft_lstsize(s);
		tmp = s;
		while (tmp != NULL)
		{
			if (curr->content < tmp->content)
				index--;
			tmp = tmp->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}

void	ft_remove_fromlst(t_list **s, int n)
{
	t_list	*tmp;
	t_list	*first;

	first = *s;
	while ((*s)->content != n && *s != NULL)
		*s = (*s)->next;
	if ((*s)->content != first->content)
	{
		tmp = *s;
		*s = tmp->prev;
		(*s)->next = tmp->next;
		*s = first;
		free(tmp);
		return ;
	}
	tmp = *s;
	*s = (*s)->next;
	free(tmp);
}
