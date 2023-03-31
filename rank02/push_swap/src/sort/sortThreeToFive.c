/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortThreeToFive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:00:03 by bverdeci          #+#    #+#             */
/*   Updated: 2023/03/31 12:40:15 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_list **s, t_result **res)
{
	t_list	*last;

	last = ft_lstlast(*s);
	if ((*s)->content > (*s)->next->content)
	{
		if ((*s)->content > last->content)
		{
			ft_lstadd_back_2(res, ft_lstnew_2(ft_rotate_a(s)));
			if ((*s)->content > (*s)->next->content)
				ft_lstadd_back_2(res, ft_lstnew_2(ft_swap_a(s)));
		}
		else
			ft_lstadd_back_2(res, ft_lstnew_2(ft_swap_a(s)));
	}
	else
	{
		if ((*s)->content > last->content)
			ft_lstadd_back_2(res, ft_lstnew_2(ft_reverse_rotate_a(s)));
		else if ((*s)->next->content > last->content)
		{
			ft_lstadd_back_2(res, ft_lstnew_2(ft_swap_a(s)));
			ft_lstadd_back_2(res, ft_lstnew_2(ft_rotate_a(s)));
		}
	}
}

/*trouver les deux plus petits nombres et les faire passer sur la stack b, 
sort la stack a avec le sort3 algo et repush sur a*/

void	ft_sort5(t_list **s_a, t_list **s_b, t_result **res)
{
	t_min_pos	minimum;

	while (ft_lstsize(*s_b) < ft_lstsize(*s_a) / 2)
	{
		minimum = ft_minimum(*s_a);
		while (minimum.min != (*s_a)->content)
		{
			if (minimum.pos >= (ft_lstsize(*s_a) / 2))
			{
				ft_lstadd_back_2(res, ft_lstnew_2(ft_reverse_rotate_a(s_a)));
			}
			else
				ft_lstadd_back_2(res, ft_lstnew_2(ft_swap_a(s_a)));
		}
		ft_lstadd_back_2(res, ft_lstnew_2(ft_push_b(s_a, s_b)));
	}
	ft_sort3(s_a, res);
	while (ft_lstsize(*s_b) > 0)
		ft_lstadd_back_2(res, ft_lstnew_2(ft_push_a(s_b, s_a)));
}
