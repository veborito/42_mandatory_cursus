/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:00:13 by bverdeci          #+#    #+#             */
/*   Updated: 2022/12/01 11:23:23 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_el)
{
	t_list	*last;

	last = *lst;
	if (*lst == NULL)
		*lst = new_el;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new_el;
	}
}
