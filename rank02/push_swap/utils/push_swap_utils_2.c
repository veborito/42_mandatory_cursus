/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:44:32 by bverdeci          #+#    #+#             */
/*   Updated: 2023/03/12 22:56:11 by bverdeci         ###   ########.fr       */
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
	int		j;
	t_list	*front;
	t_list	*back;

	front = s;
	back = ft_lstlast(s);
	i = 1;
	j = ft_lstsize(s);
	while (front != NULL && back != NULL)
	{
		if (front->index == n)
			return (i);
		if (back->index == n)
			return (j);
		front = front->next;
		back = back->prev;
		i++;
		j--;
	}
	return (0);
}

int	ft_scan_samller(t_list *s, int median)
{
	t_list	*front;
	t_list	*back;

	front = s;
	back = ft_lstlast(s);
	while (front != NULL && back != NULL)
	{
		if (front->index < median)
			return (front->index);
		if (back->index < median)
			return (back->index);
		front = front->next;
		back = back->prev;
	}
	return (0);
}
