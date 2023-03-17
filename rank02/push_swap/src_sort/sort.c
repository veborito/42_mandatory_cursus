/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:37:19 by bverdeci          #+#    #+#             */
/*   Updated: 2023/03/15 17:51:56 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static void	ft_printindex(t_list *lst)
// {
// 	while (lst)
// 	{
// 		ft_printf("%d", lst->index);
// 		ft_printf("\n");
// 		lst = lst->next;
// 	}
// }

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


void	ft_under_pivot(t_list **s_a, t_list **s_b, t_result **res, int pivot)
{
	int			size;
	t_num_pos	num_pos;
	int			i;

	i = ft_lstsize(*s_b);
	while (i < pivot - 1)
	{
		size = ft_lstsize(*s_a);
		num_pos.num = ft_scan_samller(*s_a, pivot);
		num_pos.pos = ft_getpos(*s_a, num_pos.num);
		if ((*s_a)->index < pivot)
		{
			ft_lstadd_back_2(res, ft_lstnew_2(ft_push_b(s_a, s_b)));
			i++;
		}
		else if (num_pos.pos < size / 2)
			ft_lstadd_back_2(res, ft_lstnew_2(ft_rotate_a(s_a)));
		else
			ft_lstadd_back_2(res, ft_lstnew_2(ft_reverse_rotate_a(s_a)));
	}
}

void	ft_sort(t_list **s_a, t_list **s_b, t_result **res)
{
	int	size_a;
	int	i;
	int	pivot;

	pivot = ft_lstsize(*s_a) / 2;
	size_a = ft_lstsize(*s_a);
	i = 2;
	while (ft_lstsize(*s_a) > 3)
	{
		ft_under_pivot(s_a, s_b, res, pivot);
		i += 2;
		pivot += (size_a / i);
	}
	ft_sort3(s_a, res);
	while (ft_lstsize(*s_a) != size_a && (*s_b)->next != NULL)
	{
		if ((*s_b)->content < (*s_b)->next->content)
			ft_lstadd_back_2(res, ft_lstnew_2(ft_swap_b(s_b)));
		ft_lstadd_back_2(res, ft_lstnew_2(ft_push_a(s_b, s_a)));
	}
	ft_lstadd_back_2(res, ft_lstnew_2(ft_push_a(s_b, s_a)));
}
