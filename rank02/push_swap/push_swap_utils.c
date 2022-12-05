/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:08:05 by bverdeci          #+#    #+#             */
/*   Updated: 2022/12/05 17:57:13 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlst(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d\n", lst->content);
		lst = lst->next;
	}
}

t_list	*ft_before_last(t_list *stack)
{
	t_list	*before_last;
	t_list	*last;

	before_last = stack;
	last = ft_lstlast(stack);
	while(before_last->next != last)
	{
		before_last = before_last->next;
	}
	return(before_last);
}