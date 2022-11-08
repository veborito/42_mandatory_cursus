/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:49:48 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/08 22:44:37 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

// renvoie le dernier élément de la liste

t_list	*ft_lstlast(t_list *stock)
{
	t_list	*last;

	last = stock;
	if (last) 
	{
		while (last->next != NULL)
		{
			last = last->next;
		}
		return (last);
	}
	return (NULL);
}

/* Ajoute un nouvel élément de type char * à la fin de la liste
 * (très important !!!!). */

void	ft_add_link(t_list **stock, char *buff)
{
	t_list	*new;
	t_list	*last;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->content = buff;
	last = ft_lstlast(*stock);
	if (last == NULL)
		*stock = new;
	else
		last->next = new;
}

/* Cette fonction lis le fichier correspondant a fd.
 * Ajoute le contenu du buffer dans la liste si possible.
 * Continue d'ajouter une nouvel élément à la liste tant que le caractère \n
 * n'est pas rencontré*/

void	ft_read_and_add(int fd, t_list **stock)
{
	char	*buff;
	int		output;	
	
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return ;
	output = read(fd, buff, BUFFER_SIZE);
	if (output == 0 || output == -1)
		return ;
	buff[output] = '\0';
	ft_add_link(stock, buff);
	while (!ft_is_in(buff))
	{
		output = read(fd, buff, BUFFER_SIZE);
		if (output == 0 || output == -1)
			return ;
		buff[output] = '\0';
		ft_add_link(stock, buff);
	}
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
	char	*line;
	t_list	*stock;

	stock = NULL;
	ft_read_and_add(fd, &stock);
	if (stock == NULL)
		return (NULL);

	line = stock->content;
	//1. lire ce qu'il y a dans le fichier.
	//   jusqu'a ce qu'il y ait un \n.
	//2. ajouter ce qui a été lu.
	//3. ajouter ce qu'il faut à ligne. 
	//4. nettoyer ce qui a été mis de côté.
	//   cad enlever de ma reserve ce qui
	//   a été mis dans la ligne.
	//5. retourner la ligne.
	return (line);
}
