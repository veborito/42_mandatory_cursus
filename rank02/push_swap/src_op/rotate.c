/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:19:53 by bverdeci          #+#    #+#             */
/*   Updated: 2023/01/30 09:42:24 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	return(ft_strdup("ra"));
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
	return(ft_strdup("rb"));
}