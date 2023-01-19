/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:00:03 by bverdeci          #+#    #+#             */
/*   Updated: 2023/01/09 12:19:12 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort3(t_list **s)
{
	t_list	*last;
	char	**operations;
	int		i;
	int		len;

	operations = ft_calloc(2, sizeof(char*));
	if (operations == NULL)
		return (0);
	last = ft_lstlast(*s);
	i = 0;
	if ((*s)->content > (*s)->next->content)
	{
		if ((*s)->content > last->content)
		{
			operations[i++] = ft_rotate_a(s);;
			if ((*s)->content > (*s)->next->content)
				operations[i++] = ft_swap_a(s);
		}
		else
			operations[i++] = ft_swap_a(s);
	}
	else
	{
		if ((*s)->content > last->content)
			operations[i++] = ft_reverse_rotate_a(s);
		else if ((*s)->next->content > last->content)
		{
			operations[i++] = ft_reverse_rotate_a(s);
			operations[i++] = ft_swap_a(s);
		}
	}
	len = ft_lenstring_tab(operations);
	free(operations);
	return(len);
}