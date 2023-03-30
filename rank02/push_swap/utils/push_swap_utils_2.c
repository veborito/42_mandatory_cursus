/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:44:32 by bverdeci          #+#    #+#             */
/*   Updated: 2023/03/30 19:12:49 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	ft_getpos(t_list *s, int n)
{
	int		i;
	t_list	*front;

	front = s;
	i = 1;
	while (front != NULL)
	{
		if (front->index == n)
			return (i);
		front = front->next;
		i++;
	}
	return (0);
}

int	ft_scan_samller(t_list *s, int median)
{
	t_list	*front;
	int		i;

	front = s;
	i = 0;
	while (i < ft_lstsize(s) / 2)
	{
		if (front->index <= median)
			return (front->index);
		front = front->next;
		i += 1;
	}
	return (0);
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
