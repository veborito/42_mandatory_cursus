/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:35:50 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/23 09:17:42 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// affiche ma liste (utilisé pour debug)

void	ft_print_list(t_list *stock)
{
	t_list	*tmp;

	tmp = stock;
	printf("début de ma liste:\n");
	while (tmp != NULL)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
	printf("fin de ma liste:\n");
}

// trouve le dernier el de ma liste

t_list	*ft_lstlast(t_list *stock)
{
	t_list	*last;

	if (stock == NULL)
		return (stock);
	last = stock;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

// ajoute ce qui a été lu dans ma liste

void	ft_lstadd_back(t_list **stock, char *buff)
{
	t_list	*new;
	t_list	*last;
	int		i;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->content = malloc(sizeof(char) * (ft_strlen(buff) + 1));
	if (new->content == NULL)
		return ;
	i = -1;
	while (buff[++i])
		new->content[i] = buff[i];
	new->content[i] = '\0';
	if (*stock == NULL)
	{
		*stock = new;
		(*stock)->next = NULL;
		return ;
	}
	last = ft_lstlast(*stock);
	last->next = new;
	new->next = NULL;
}

// check si c dans la content de la liste

int	ft_in_list(t_list *stock, int c)
{
	t_list	*last;
	int		i;

	last = ft_lstlast(stock);
	i = 0;
	while (last && last->content[i])
	{
		if (last->content[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/* lire le fichier tant que un \n 
 * n'est pas croisé et ajouter ça dans mon stock
 */

void	ft_read_add(int fd, t_list **stock, int *output)
{
	char	*buff;

	while (!ft_in_list(*stock, '\n'))
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == NULL)
			return ;
		*output = read(fd, buff, BUFFER_SIZE);
		if (*output == -1)
		{
			free(buff);
			return ;
		}
		buff[*output] = '\0';
		ft_lstadd_back(stock, buff);
		free(buff);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*stock = NULL;
	int				output;
	char			*line;

	line = NULL;
	if (fd < 0 || read(fd, 0, 0) == -1 || BUFFER_SIZE < 0)
		return (NULL);
	ft_read_add(fd, &stock, &output);
	if (output == -1 || stock == NULL)
		return (NULL);
	ft_lst_toline(stock, &line);
	ft_print_list(stock);
	return (line);
}
