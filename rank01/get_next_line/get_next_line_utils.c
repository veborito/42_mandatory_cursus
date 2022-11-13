/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:57:41 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/13 16:08:16 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdio.h>

// fonction qui affiche le contenu des el de la liste (pour debug)
/*
void	ft_printlist(t_list *stock)
{
	t_list	*st;
	int		i;

	i = 1;
	st = stock;
	while (st != NULL)
	{
		printf("el %d : %s\n", i, st->content);
		st = st->next;
		i++;
	}
}
*/

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
	last = ft_lstlast(*stock);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	j = i;
	while (last->content[j])
		j++;
	updt->content = malloc(sizeof(char) * (j - i + 1));
	if (updt == NULL || updt->content == NULL)
		return ;
	updt->next = NULL;
	j = 0;
	while (last->content[i])
		updt->content[j++] = last->content[i++];
	updt->content[j] = '\0';
	ft_clearlst(stock);
	*stock = updt;
}

//libère la totalité de l'espace mémoire de la liste

void	ft_clearlst(t_list **stock)
{
	t_list	*curr;
	t_list	*tmp;

	curr = *stock;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp->content);
		free(tmp);
	}
	*stock = NULL;
}

// ajoute dans line le contenu du stock jusqu'à ce qu'il y ait un \n

int	ft_count_from_list(t_list *stock)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = stock;
	j = 0;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->content[i] && (tmp->content[i] != '\n'))
		{
			i++;
			j++;
		}
		if (tmp->content[i] == '\n')
		{
			j++;
			break ;
		}
		tmp = tmp->next;
	}
	return (j);
}

// regarde s'il y a un \n dans le contenu du nouvel élément de la liste

int	ft_is_in_list(t_list *stock)
{
	t_list	*last;
	int		i;

	last = ft_lstlast(stock);
	i = 0;
	if (last)
	{
		while (last->content[i])
		{
			if (last->content[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}
