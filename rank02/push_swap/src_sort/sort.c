/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:37:19 by bverdeci          #+#    #+#             */
/*   Updated: 2023/03/30 19:37:08 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_printindex(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d", lst->index);
		ft_printf("\n");
		lst = lst->next;
	}
}

int	ft_is_sorted_a(t_list *s)
{
	while (s->next != NULL)
	{
		if (s->content > s->next->content)
			return (0);
		s = s->next;
	}
	return (1);
}

int	ft_is_sorted_b(t_list *s)
{
	while (s->next != NULL)
	{
		if (s->content < s->next->content)
			return (0);
		s = s->next;
	}
	return (1);
}

void	ft_radix(t_list **s_a, t_list **s_b, t_result **res)
{
	
}