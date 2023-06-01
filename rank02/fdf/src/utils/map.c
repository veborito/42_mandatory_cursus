/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:35:07 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/01 18:33:51 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	***copy_map(char ***map, int size)
{
	char	***new_map;
	int		i;

	i = 0;
	new_map = ft_calloc(size, sizeof(char **));
	if (!new_map)
		return (NULL);
	while (map[i])
	{
		new_map[i] = copy_strtab(map[i]);
		i++;
	}
	return (new_map);
}

char	***realloc_strtab(char ***map, char **row, int size)
{
	char	***new_map;

	if (!map)
	{
		new_map = ft_calloc(size + 1, sizeof(char **));
		if (!new_map)
			return (NULL);
		new_map[0] = copy_strtab(row);
		strtab_clear(row);
		return (new_map);
	}
	else
	{
		new_map = copy_map(map, size + 1);
		new_map[size - 1] = copy_strtab(row);
	}
	clear_map(map);
	strtab_clear(row);
	return (new_map);
}

char	***create_map(int fd)
{
	int		size;
	char	*line;
	char	*trim;
	char	***map;

	map = NULL;
	size = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		size++;
		trim = ft_strtrim(line, "\n");
		map = realloc_strtab(map, ft_split(trim, ' '), size);
		if (!map)
			exit(1);
		free(line);
		line = get_next_line(fd);
		free(trim);
	}
	return (map);
}

int	map_len(char ***map)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}

t_min_max	min_max_z(t_point **p_map, char ***map)
{
	int			i;
	int			j;
	int			max;
	int			min;
	t_min_max	min_max;

	i = 0;
	max = 0;
	min = 0;
	while (p_map[i])
	{
		j = 0;
		while (j < strtab_len(map[i]))
		{
			if (max < p_map[i][j].z)
				max = p_map[i][j].z;
			if (min > p_map[i][j].z)
				min = p_map[i][j].z;
			j++;
		}
		i++;
	}
	min_max.min = min;
	min_max.max = max;
	return (min_max);
}
