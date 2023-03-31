/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:08:05 by bverdeci          #+#    #+#             */
/*   Updated: 2023/03/31 12:39:54 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lenstring_tab(char **stab)
{
	int	i;

	i = 0;
	while (stab[i] != 0)
		i++;
	return (i);
}

void	ft_printlst(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d", lst->content);
		ft_printf("\n");
		lst = lst->next;
	}
}

t_list	*ft_before_last(t_list *stack)
{
	t_list	*before_last;
	t_list	*last;

	before_last = stack;
	last = ft_lstlast(stack);
	while (before_last->next != last)
	{
		before_last = before_last->next;
	}
	return (before_last);
}

void	ft_clearlst(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (*stack != NULL)
	{
		*stack = (*stack)->next;
		free(tmp);
		tmp = *stack;
	}
}

t_min_pos	ft_minimum(t_list *stk_a)
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
