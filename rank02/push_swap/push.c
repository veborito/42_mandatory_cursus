/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:42:37 by bverdeci          #+#    #+#             */
/*   Updated: 2022/12/05 18:22:42 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Push from stack A to stack B et vice versa */

#include "push_swap.h"

void	ft_push(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
}
