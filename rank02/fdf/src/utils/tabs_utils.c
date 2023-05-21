/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:16:12 by bverdeci          #+#    #+#             */
/*   Updated: 2023/05/20 12:43:05 by bverdeci         ###   ########.fr       */
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

char	**copy_strtab(char **tab)
{
	char	**new_tab;
	int		i;

	i = 0;
	new_tab = ft_calloc(sizeof(char *), strtab_len(tab) + 1);
	if (!new_tab)
		return (NULL);
	while (tab[i])
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	return (new_tab);
}

void	clear_map(char ***map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		strtab_clear(map[i]);
		i++;
	}
	free(map);
}
