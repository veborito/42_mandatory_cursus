/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:37:29 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/28 16:57:40 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
	lst = temp;
}

/*
en récursif pour le fun

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	if (lst == NULL)
		return ;
	ft_lstiter(lst->next, f);
	f(lst->content);
	lst = temp;
}
*/
