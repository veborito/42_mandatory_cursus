/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:35:07 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/01 16:14:20 by bverdeci         ###   ########.fr       */
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

char	***create_map(char **av)
{
	int		fd;
	int		size;
	char	*line;
	char	*trim;
	char	***map;

	fd = open(av[1], O_RDONLY, S_IRUSR | S_IWUSR);
	if (fd == -1)
		throw_error();
	map = NULL;
	size = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		size++;
		trim = ft_strtrim(line, "\n");
		map = realloc_strtab(map, ft_split(trim, ' '), size);
		if (!map)
			throw_error();
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
