/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:49:48 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/10 11:10:06 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdio.h>

// ajouter le contenu de stock (jusqu'à \n) dans line 
void	ft_add_from_list(t_list *stock, char *line)
{
	int		i;
	int		j;
	int		flag;
	t_list *tmp;

	flag = 0;
	j = 0;
	tmp = stock;
	while (tmp != NULL && flag == 0)
	{
		i = 0;
		while (tmp->content[i] && tmp->content[i] != '\n')
		{
			line[j] = tmp->content[i];
			i++;
			j++;
		}
		if (tmp->content[i] == '\n')
		{
			line[j] = '\n';
			j++;
			flag = 1;
		}
		tmp = tmp->next;
	}
	line[j] = '\0';
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

void	ft_add_link(t_list **stock, char *buff)
{
	t_list	*new;
	t_list	*last;
	int		len;

	len = (int)ft_strlen(buff);
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->content = malloc(sizeof(char) * (len + 1));
	new->next = NULL;
	if (new->content == NULL)
		return ;
	len = -1;
	while (buff[++len])
		new->content[len] = buff[len];
	if (*stock == NULL)
	{
		*stock = new;
		return ;
	}
	last = ft_lstlast(*stock);
	last->next = new;
}

// fonction qui affiche le contenu des el de la liste (pour debug)

void	ft_printlist(t_list *stock)
{
	t_list *st;
	int		i;

	i = 1;
	st = stock;
	while (st != NULL)
	{
		printf("el numero %d : %s\n", i , st->content);
		st = st->next;
		i++;
	}
}

/* Cette fonction lis le fichier correspondant a fd.
 * Ajoute le contenu du buffer dans la liste si possible.
 * Continue d'ajouter une nouvel élément à la liste tant que le caractère \n
 * n'est pas rencontré*/

void	ft_read_and_add(int fd, t_list **stock, int *output)
{
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return ;
	while (!ft_is_in(buff))
	{
		*output = read(fd, buff, BUFFER_SIZE);
		printf("ce qui a été lu -----> %s\n", buff);
		if (*output == 0 || *output == -1)
			return ;
		buff[*output] = '\0';
		ft_add_link(stock, buff);
	}
	printf("------------------------\n\n");
	ft_printlist(*stock);
	printf("------------------------\n\n");
}

// Affiche la prochaine ligne 

/* Affiche une par une les lignes d'un fichier. Lors de chaque appel de la 
 * fonction. Donc par exemple lorsqu'on appel la fonction dans une bouvle
 * jusqu'a ce que ce ne soit plus possible de lire le fichier. Les lignes
 * sont affichées une par une.
 *
 * 
 * valeurs de retour : la ligne lue, NULL si erreur ou fin du fichier*/

char	*get_next_line(int fd)
{
	static t_list	*stock = NULL;
	char			*line;
	int				len;
	int				output;

	if (fd == 0 || fd == -1)
		return (NULL);
	ft_read_and_add(fd, &stock, &output);
	if (output == 0 || output == -1)
		return (NULL);
	len = ft_count_from_list(stock);
	line = malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	ft_add_from_list(stock, line);
	if (line == NULL)
	{
		ft_clearlst(&stock);
		free(line);
		return (NULL);
	}
	ft_update_stock(&stock);
	return (line);
}
