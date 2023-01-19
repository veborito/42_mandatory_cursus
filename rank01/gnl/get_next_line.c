/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:09:56 by bverdeci          #+#    #+#             */
/*   Updated: 2022/12/16 18:35:47 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *stock)
{
	char	*buff;
	int		output;

	output = 1;
	while (!ft_find_nl(stock) && output > 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		output = read(fd, buff, BUFFER_SIZE);
		if (output == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[output] = 0;
		stock = ft_add_and_free(stock, buff);
		free(buff);
	}
	return (stock);
}

static char	*ft_line(char *stock)
{
	char	*line;
	int		len;
	int		i;

	if (stock[0] == 0 || !stock)
		return (NULL);
	len = 0;
	while (stock[len] && stock[len] != '\n')
		len++;
	if (stock[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (stock[++i] && stock[i] != '\n')
		line[i] = stock[i];
	if (stock[i] == '\n')
		line[i] = '\n';
	line[len] = 0;
	return (line);
}

static char	*ft_update(char *stock)
{
	char	*new_stock;
	int		i;
	int		j;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == 0)
	{
		free(stock);
		return (NULL);
	}
	if (stock[i] == '\n')
		i++;
	new_stock = malloc(sizeof(char) * (ft_len(stock) - i + 1));
	if (!new_stock)
		return (NULL);
	j = 0;
	while (stock[i])
		new_stock[j++] = stock[i++];
	new_stock[j] = 0;
	free(stock);
	return (new_stock);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	if (!stock)
	{
		stock = malloc(sizeof(char) * 1);
		if (!stock)
			return (NULL);
		stock[0] = 0;
	}
	stock = read_file(fd, stock);
	line = ft_line(stock);
	stock = ft_update(stock);
	return (line);
}
