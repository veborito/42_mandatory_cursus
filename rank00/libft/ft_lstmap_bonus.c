/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:32:33 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/29 13:24:02 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*elem;
	t_list	*curr;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	nlst = NULL;
	curr = lst;
	while (curr)
	{
		temp = f(curr->content);
		elem = ft_lstnew(temp);
		if (!elem)
		{
			ft_lstclear(&nlst, del);
			if (temp)
				del(temp);
			return (NULL);
		}
		ft_lstadd_back(&nlst, elem);
		curr = curr->next;
	}
	return (nlst);
}
