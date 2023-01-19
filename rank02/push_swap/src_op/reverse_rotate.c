/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:20:00 by bverdeci          #+#    #+#             */
/*   Updated: 2023/01/19 12:46:43 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_reverse_rotate_a(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*before_last;

	first = *stack;
	before_last = ft_before_last(*stack);
	last = ft_lstlast(*stack);
	last->next = first;
	before_last->next = NULL;
	*stack = last;
	return ("rra");
}

char	*ft_reverse_rotate_b(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*before_last;

	first = *stack;
	before_last = ft_before_last(*stack);
	last = ft_lstlast(*stack);
	last->next = first;
	before_last->next = NULL;
	*stack = last;
	return("rrb");
}