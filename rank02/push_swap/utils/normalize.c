/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:45:49 by bverdeci          #+#    #+#             */
/*   Updated: 2023/03/10 17:06:22 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_normalize(t_list *s)
{
	int		index;
	t_list	*tmp;
	t_list	*curr;

	curr = s;
	while (curr != NULL)
	{
		index = ft_lstsize(s);
		tmp = s;
		while (tmp != NULL)
		{
			if (curr->content < tmp->content)
				index--;
			tmp = tmp->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}
