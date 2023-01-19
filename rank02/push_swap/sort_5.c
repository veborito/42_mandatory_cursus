/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:31:57 by bverdeci          #+#    #+#             */
/*   Updated: 2023/01/09 12:21:38 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_min_pos	ft_minimum(t_list *stk_a)
{
	t_list		*tmp;
	t_list		*stk;
	t_min_pos	minimum;

	tmp = stk_a;
	stk = stk_a;
	minimum.min = tmp->content;
	while (tmp != NULL)
	{
		if (minimum.min > tmp->content)
			minimum.min = tmp->content;
		tmp = tmp->next;
	}
	minimum.pos = 0;
	while (stk != NULL)
	{
		if (minimum.min == stk->content && stk != NULL)
			return (minimum);
		(minimum.pos)++;
		stk = stk->next;
	}
	return (minimum);
}

/*trouver les deux plus petits nombres et les faire passer sur la stack b sort la stack a avec le sort3 algo*/

int	ft_sort5(t_list **s_a, t_list **s_b)
{
	t_min_pos	minimum;

	while (ft_lstsize(*s_b) < ft_lstsize(*s_a) / 2)
	{
		minimum = ft_minimum(*s_a);
		while (minimum.min != (*s_a)->content)
		{
			if (minimum.pos >= (ft_lstsize(*s_a) / 2))
			{
				ft_reverse_rotate_a(s_a);
			}
			else
				ft_swap_a(s_a);
		}
		ft_push_a(s_a, s_b);
	}
	ft_sort3(s_a);
	while(ft_lstsize(*s_b) > 0)
		ft_push_b(s_b, s_a);
	return (1);
}