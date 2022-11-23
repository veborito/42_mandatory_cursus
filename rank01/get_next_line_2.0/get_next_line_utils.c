/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:35:55 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/23 09:20:36 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_lst_strlen(t_list *lst)
{
	t_list	*tmp;
	size_t	len;
	int		i;

	len = 0;
	tmp = lst;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i] && tmp->content[i] != '\n')
		{
			len++;
			i++;
		}
		if (tmp->content[i] == '\n')
		{
			len++;
			return (len);
		}
		tmp = tmp->next;
	}
	return (len);
}

void	ft_lst_toline(t_list *stock, char **line)
{
	t_list	*tmp;
	int		i;
	int		j;
	size_t	len;

	tmp = stock;
	len = ft_lst_strlen(tmp);
	*line = malloc(sizeof(char) * (len + 1));
	if (*line == NULL)
		return ;
	i = 0;
	while (tmp)
	{
		j = 0;
		while (tmp->content[j] && tmp->content[j] != '\n')
			(*line)[i++] = tmp->content[j++];
		if (tmp->content[j] == '\n')
		{
			(*line)[i++] = '\n';
			break ;
		}
		tmp = tmp->next;
	}
	(*line)[i] = '\0';
}
