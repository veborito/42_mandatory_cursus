/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:49:48 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/29 00:15:49 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
// fonction qui affiche le contenu des el de la liste (pour debug)
/*
void	ft_printlist(t_list *stock)
{
	t_list *st;
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

// ajouter le contenu de stock (jusqu'à \n) dans line 
char	*ft_add_from_list(t_list *stock, int len)
{
	int		i;
	int		j;
	t_list	*tmp;
	char	*line;

	tmp = stock;
	line = malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	j = 0;
	while (tmp != NULL)
	{
		i = 0;
		while ((tmp->content[i] != '\0') && (tmp->content[i] != '\n'))
			line[j++] = tmp->content[i++];
		if (tmp->content[i] == '\n')
		{
			line[j] = '\n';
			break ;
		}
		tmp = tmp->next;
	}
	line[len] = '\0';
	return (line);
}

// renvoie le dernier élément de la liste

t_list	*ft_lstlast(t_list *stock)
{
	t_list	*last;

	if (stock == NULL)
		return (NULL);
	last = stock;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

/* Ajoute un nouvel élément de type char * à la fin de la liste
 * (très important !!!!). */

void	ft_add_link(t_list **stock, char *buff, int output)
{
	t_list	*new;
	t_list	*last;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->content = malloc(sizeof(char) * (output + 1));
		if (new->content)
		{
			new->next = NULL;
			output = -1;
			while (buff[++output] != '\0')
				new->content[output] = buff[output];
			new->content[output] = '\0';
			if (*stock == NULL)
			{
				*stock = new;
				return ;
			}
			last = ft_lstlast(*stock);
			last->next = new;
		}
	}
}

/* Cette fonction lis le fichier correspondant a fd.
 * Ajoute le contenu du buffer dans la liste si possible.
 * Continue d'ajouter une nouvel élément à la liste tant que le caractère \n
 * n'est pas rencontré*/

void	ft_read_and_add(int fd, t_list **stock)
{
	char	*buff;
	int		output;

	output = 1;
	while (!ft_is_in_list(*stock) && output > 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == NULL)
			return ;
		output = read(fd, buff, BUFFER_SIZE);
		if (output == 0 || output == -1)
		{
			free(buff);
			return ;
		}
		buff[output] = '\0';
		ft_add_link(stock, buff, output);
		free(buff);
	}
}

// Affiche la prochaine ligne 

/* Affiche une par une les lignes d'un fichier. Lors de chaque appel de la 
 * fonction. Donc par exemple lorsqu'on appelle la fonction dans une boucle
 * on affiche chaque ligne jusqu'a ce que ce ne soit plus possible de lire 
 * le fichier. Les lignes sont affichées une par une.
 *
 * valeurs de retour : la ligne lue, NULL si erreur ou fin du fichier*/

char	*get_next_line(int fd)
{
	static t_list	*stock = NULL;
	char			*line;

	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		ft_clearlst(&stock);
		stock = NULL;
		return (NULL);
	}
	line = NULL;
	ft_read_and_add(fd, &stock);
	if (stock == NULL)
		return (NULL);
	line = ft_add_from_list(stock, ft_count_from_list(stock));
	ft_update_stock(&stock);
	if (stock == NULL || line[0] == '\0')
	{
		free(line);
		line = NULL;
		ft_clearlst(&stock);
		stock = NULL;
		return (NULL);
	}
	return (line);
}
