/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:00:03 by bverdeci          #+#    #+#             */
/*   Updated: 2023/01/19 12:46:41 by bverdeci         ###   ########.fr       */
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
			ft_rotate_a(s);
			if ((*s)->content > (*s)->next->content)
				ft_swap_a(s);
		}
		else
			ft_swap_a(s);
	}
	else
	{
		if ((*s)->content > last->content)
			ft_reverse_rotate_a(s);	
		else if ((*s)->next->content > last->content)
		{
			ft_reverse_rotate_a(s);
			ft_swap_a(s);
		}
	}
}