/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:57:41 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/10 01:01:23 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// stock les éléments après |n
// c'était une vraie galère

void	ft_update_stock(t_list **stock)
{
	int		i;
	int		j;
	t_list	*updt;
	t_list	*last;

	updt = malloc(sizeof(t_list));
	if (updt == NULL)
		return ;
	last = ft_lstlast(*stock);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	updt->content = malloc(sizeof(char) * (ft_strlen(last->content) - i + 1));
	if (updt->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		updt->content[j++] = last->content[i++];
	*stock = updt;
}

//libère la totalité de l'espace mémoire de la liste

void	ft_clearlst(t_list **stock)
{
	t_list	*tmp;

	while (stock != NULL)
	{
		tmp = *stock;
		*stock = (*stock)->next;
		free(tmp->content);
		free(tmp);
	}
	*stock = NULL;
}

// ajoute dans line le contenu du stock jusqu'à ce qu'il y ait un \n

int	ft_count_from_list(t_list *stock)
{
	int	i;
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	while (stock != NULL && flag == 0)
	{
		i = 0;
		while (stock->content[i] && stock->content[i] != '\n')
		{
			i++;
			j++;
		}
		if (stock->content[i] == '\n')
		{
			flag = 1;
			j++;
		}
		stock = stock->next;
	}
	return (j);
}

// regarde s'il y a un \n dans le contenu du nouvel élément de la liste

int	ft_is_in(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
