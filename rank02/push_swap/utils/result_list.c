/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:55:17 by bverdeci          #+#    #+#             */
/*   Updated: 2023/03/30 19:03:13 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_result	*ft_lstnew_2(char *str)
{
	t_result			*list;

	list = malloc(sizeof(t_result));
	if (list)
	{
		list->operation = str;
		list->next = NULL;
	}
	return (list);
}

void	ft_lstadd_back_2(t_result **lst, t_result *new_el)
{
	t_result	*last;

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

void	ft_printres(t_result *lst)
{
	while (lst)
	{
		ft_printf("%s\n", lst->operation);
		lst = lst->next;
	}
}

void	ft_clearres(t_result **res)
{
	t_result	*tmp;

	tmp = *res;
	while (*res != NULL)
	{
		*res = (*res)->next;
		free(tmp->operation);
		free(tmp);
		tmp = *res;
	}
}

int	ft_res_size(t_result *lst)
{
	int	i;

	i = 0;
	if (lst)
	{
		while (lst)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}
