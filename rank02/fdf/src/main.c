/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:58:46 by bverdeci          #+#    #+#             */
/*   Updated: 2023/05/25 20:10:37 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	throw_error(void)
{
	perror("Error ");
	exit(1);
}

void	add_point(t_point **p_map, char **row, int line)
{
	int		col;
	char	**split;
	char	*color;

	col = 0;
	while (row[col])
	{
		p_map[line][col].x = col;
		p_map[line][col].y = line;
		p_map[line][col].z = ft_atoi(row[col]);
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
		col++;
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
		add_point(p_map, map[i], i);
		i++;
	}
	p_map[i] = NULL;
	return (p_map);
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_pixel	img;
	char	***map;
	t_point	**p_map;
	t_point	p1;
	t_point	p2;

	if (ac == 2)
	{
		map = create_map(av);
		p_map = p_create_map(map);
		set_point(p1, p_map);
		draw_line(&img, p1, p2);
	}
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "FIL DE FER");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	exit(0);
}
	// void	*mlx;
	// void	*mlx_win;
	// t_pixel	img;
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "FIL DE FER");
	// img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	// 		&img.line_length, &img.endian);	
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
