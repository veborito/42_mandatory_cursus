/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:58:46 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/01 18:40:44 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_event(int keycode, t_fdf *fdf)
{
	if (keycode == KEYCODE_ESC)
		close_win(fdf);
	return (0);
}

int	close_win(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->mlx_win);
	exit (0);
}

int	check_map(char ***map)
{
	int	col_len;
	int	i;

	col_len = strtab_len(map[0]);
	i = 0;
	while (map[i])
	{
		if (col_len != strtab_len(map[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	start_fdf(t_fdf fdf, int fd)
{
	t_pixel	img;

	fdf.map = create_map(fd);
	if (!fdf.map || check_map(fdf.map))
	{
		perror("Mauvais format de map ");
		exit(1);
	}
	fdf.p_map = p_create_map(fdf.map);
	fdf.mlx = mlx_init();
	fdf.mlx_win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "FIL DE FER");
	img.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw_map(fdf.p_map, fdf.map, img);
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, img.img, 0, 0);
	mlx_key_hook(fdf.mlx_win, key_event, &fdf);
	mlx_hook(fdf.mlx_win, ON_DESTROY, 0, close_win, &fdf);
	mlx_loop(fdf.mlx);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;
	int		fd;

	if (ac == 2)
	{
		ft_bzero(&fdf, sizeof(fdf));
		fd = open(av[1], O_RDONLY, S_IRUSR | S_IWUSR);
		if (fd == -1)
		{
			perror("Error ");
			exit(1);
		}
		start_fdf(fdf, fd);
		exit(0);
	}
	else if (ac > 2)
		perror("Too much arguments ");
	else
		perror("Too few arguments ");
	exit(1);
}
