/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:26:44 by bverdeci          #+#    #+#             */
/*   Updated: 2022/12/16 17:30:39 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_add_stock(char *stock, char *buff)
{
	char	*new_stock;
	int		i;
	int		j;
	int		len;

	len = ft_len(stock) + ft_len(buff);
	new_stock = malloc(sizeof(char) * len + 1);
	if (!new_stock)
		return (NULL);
	i = 0;
	j = 0;
	while (stock[i])
		new_stock[j++] = stock[i++];
	i = 0;
	while (buff[i])
		new_stock[j++] = buff[i++];
	new_stock[len] = 0;
	return (new_stock);
}

char	*ft_add_and_free(char *stock, char *buff)
{
	char	*temp;

	temp = ft_add_stock(stock, buff);
	free(stock);
	return (temp);
}

int	ft_find_nl(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
