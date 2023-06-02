/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:27:31 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/01 18:54:07 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_color(t_point **p_map, char **row, int line, int col)
{
	char	**split;
	char	*color;

	if (ft_in_str(row[col], ','))
	{
		split = ft_split(row[col], ',');
		color = str_upper(split[1]);
		p_map[line][col].color = ft_atoi_base(color, "0123456789ABCDEF");
		strtab_clear(split);
		free(color);
	}
	else
		p_map[line][col].color = BASIC_COLOR;
}

void	add_point(t_point **p_map, char ***map, char **row, int line)
{
	int		col;
	int		ecart_x;
	int		ecart_y;

	col = 0;
	ecart_x = 0;
	ecart_y = (HEIGHT / map_len(map)) / 3 * line;
	while (row[col])
	{
		p_map[line][col].x = col;
		p_map[line][col].x = col;
		if (col > 0)
			p_map[line][col].x = col + ecart_x;
		p_map[line][col].y = line;
		if (line > 0)
			p_map[line][col].y = line + ecart_y;
		p_map[line][col].z = ft_atoi(row[col]);
		set_color(p_map, row, line, col);
		col++;
		ecart_x += (WIDTH / strtab_len(map[0])) / 3;
	}
}

t_point	**p_create_map(char ***map)
{
	t_point	**p_map;
	int		i;

	p_map = malloc(sizeof(t_point *) * map_len(map) + 1);
	if (!p_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		p_map[i] = malloc(sizeof(t_point) * strtab_len(map[i]) + 1);
		add_point(p_map, map, map[i], i);
		i++;
	}
	p_map[i] = NULL;
	return (p_map);
}

t_point	set_point(t_point **p_map, int row, int col, t_min_max z_min_max)
{
	t_point		p;

	p.x = p_map[row][col].x;
	p.y = p_map[row][col].y;
	p.z = p_map[row][col].z;
	if (z_min_max.max < 50 && z_min_max.min > -50)
		p.z = p_map[row][col].z * 3;
	if (z_min_max.max < 10 && z_min_max.min > -10)
		p.z = p_map[row][col].z * 10;
	p.color = p_map[row][col].color;
	iso_transfo(&p.x, &p.y, p.z);
	p.x += WIDTH / 3;
	p.y += 200;
	return (p);
}

void	iso_transfo(int *x, int *y, int z)
{
	int		old_x;
	int		old_y;

	old_x = *x;
	old_y = *y;
	*x = (old_x - old_y) * cos(0.523599);
	*y = -z + (old_x + old_y) * sin(0.523599);
}
