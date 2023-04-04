/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:58:46 by bverdeci          #+#    #+#             */
/*   Updated: 2023/04/03 18:47:28 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_pixel *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_h(t_pixel *data, int x, int y, int len)
{
	int	i;

	i = x - 1;
	while (++i < len)
		my_mlx_pixel_put(data, i, y, 0x00FFFFFF);
}

void	ft_draw_v(t_pixel *data, int x, int y, int len)
{
	int	i;

	i = y - 1;
	while (++i < len)
		my_mlx_pixel_put(data, x, i, 0x00FFFFFF);
}

void	ft_put_nextcoord(t_pixel *data, t_coord)
{
	
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_pixel	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "FIL DE FER");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
