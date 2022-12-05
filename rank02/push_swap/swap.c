/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:19:42 by bverdeci          #+#    #+#             */
/*   Updated: 2022/12/05 23:26:29 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap_a(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	ft_printf("sa\n");
	return (1);
}

int	ft_swap_b(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	ft_printf("sb\n");
	return (1);
}