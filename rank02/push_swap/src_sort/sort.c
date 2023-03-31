/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:37:19 by bverdeci          #+#    #+#             */
/*   Updated: 2023/03/31 01:05:35 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort(t_list **s_a, t_list **s_b, t_result **res)
{
	int	size;
	int	nb_bits;
	int	i;
	int	j;

	size = ft_lstsize(*s_a);
	nb_bits = 0;
	while ((size >> nb_bits) != 0)
		nb_bits++;
	i = 0;
	while (i < nb_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*s_a)->index >> i & 1) == 1)
				ft_lstadd_back_2(res, ft_lstnew_2(ft_rotate_a(s_a)));
			else
				ft_lstadd_back_2(res, ft_lstnew_2(ft_push_b(s_a, s_b)));
			j++;
		}
		while (ft_lstsize(*s_b) > 0)
			ft_lstadd_back_2(res, ft_lstnew_2(ft_push_a(s_b, s_a)));
		i++;
	}
}
