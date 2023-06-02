/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:46:58 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/28 16:53:43 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*temp;

	curr = *lst;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		ft_lstdelone(temp, del);
	}
	*lst = NULL;
}

/*
en récursif pour le fun

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (*lst == NULL)
		return ;
	ft_lstclear(&((*lst)->next), del);
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
*/
