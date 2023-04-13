/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:39:18 by bverdeci          #+#    #+#             */
/*   Updated: 2023/04/13 17:55:32 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pointList	*ft_pointlast(t_pointList *lst)
{
	t_pointList	*last;

	if (lst == NULL)
		return (lst);
	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	ft_pointadd_back(t_pointList **lst, t_pointList *new_el)
{
	t_pointList	*last;

	last = *lst;
	if (*lst == NULL)
	{
		*lst = new_el;
		(*lst)->prev = NULL;
	}
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new_el;
		last->next->prev = last;
	}
}

t_pointList	*ft_pointnew(t_point *point)
{
	t_pointList			*list;

	list = malloc(sizeof(t_list));
	if (list)
	{
		list->point = *point;
		list->next = NULL;
	}
	return (list);
}