/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:58:46 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/01 16:07:22 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	throw_error(void)
{
	perror("Error ");
	exit(1);
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

void	draw_map(t_point **p_map, t_pixel img, int len)
{
	int			i;
	int			j;
	t_square	s;

	ft_bzero(&s, sizeof(t_square));
	i = -1;
	while (p_map[++i])
	{
		j = -1;
		while (++j < len - 1)
		{
			s.p1 = set_point(p_map, i, j);
			s.p2 = set_point(p_map, i, j + 1);
			draw_line(&img, s.p1, s.p2);
			if (p_map[i + 1])
			{
				s.p3 = set_point(p_map, i + 1, j);
				s.p4 = set_point(p_map, i + 1, j + 1);
				draw_line(&img, s.p1, s.p3);
				draw_line(&img, s.p2, s.p4);
			}
		}
	}
}

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

int	main(int ac, char **av)
{
	t_fdf	fdf;
	t_pixel	img;

	if (ac == 2)
	{
		ft_bzero(&fdf, sizeof(fdf));
		fdf.map = create_map(av);
		fdf.p_map = p_create_map(fdf.map);
		fdf.mlx = mlx_init();
		fdf.mlx_win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "FIL DE FER");
		img.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		draw_map(fdf.p_map, img, strtab_len(fdf.map[0]));
		mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, img.img, 0, 0);
		mlx_key_hook(fdf.mlx_win, key_event, &fdf);
		mlx_hook(fdf.mlx_win, ON_DESTROY, 0, close_win, &fdf);
		mlx_loop(fdf.mlx);
		exit(0);
	}
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
