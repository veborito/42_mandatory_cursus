/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:42:37 by bverdeci          #+#    #+#             */
/*   Updated: 2023/01/30 13:38:54 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Push from stack A to stack B et vice versa */

#include "../push_swap.h"

char	*ft_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	return (ft_strdup("pb"));
}

char	*ft_push_a(t_list **stack_b, t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	return (ft_strdup("pa"));
}
