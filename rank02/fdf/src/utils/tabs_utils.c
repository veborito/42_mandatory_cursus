/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:16:12 by bverdeci          #+#    #+#             */
/*   Updated: 2023/04/14 16:45:21 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	strtab_len(char **s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	strtab_clear(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

int	matrix_len(int **matrix)
{
	int	len;

	len = 0;
	while (matrix[len])
		len++;
	return (len);
}

int	tab_len(int	*tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

void	add_to_tab(int *tab, char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		tab[i] = atoi(s[i][0]);
		i++;
	}
}
