/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:20:00 by bverdeci          #+#    #+#             */
/*   Updated: 2022/12/05 23:41:51 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_reverse_rotate_a(t_list **stack)
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
	ft_printf("rra\n");
	return (1);
}

int	ft_reverse_rotate_b(t_list **stack)
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
	ft_printf("rrb\n");
	return (1);
}