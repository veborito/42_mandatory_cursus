/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateAndRevRotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:20:00 by bverdeci          #+#    #+#             */
/*   Updated: 2023/03/31 12:40:20 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_rotate_a(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	first = *stack;
	second = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = first;
	first->next = NULL;
	*stack = second;
	return (ft_strdup("ra"));
}

char	*ft_rotate_b(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	first = *stack;
	second = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = first;
	first->next = NULL;
	*stack = second;
	return (ft_strdup("rb"));
}

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
	return (ft_strdup("rra"));
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
	return (ft_strdup("rrb"));
}
