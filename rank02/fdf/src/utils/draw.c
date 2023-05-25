/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:56:08 by bverdeci          #+#    #+#             */
/*   Updated: 2023/05/25 17:19:05 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Ajoute un pixel à l'image */
void	my_mlx_pixel_put(t_pixel *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	algorithm(t_pixel *img, t_point p1, t_point p2, t_point s)
{
	t_point	curr;
	t_point	d;
	int		error[2];

	d.x = abs(p2.x - p1.x);
	d.y = -abs(p2.y - p1.y);
	error[0] = d.x + d.y;
	curr = p1;
	while (curr.x != p2.x || curr.y != p2.y)
	{
		my_mlx_pixel_put(img, curr.x, curr.y, 0x00FF0000);
		error[1] = 2 * error[0];
		if (error[1] > d.y)
		{
			error[0] += d.y;
			curr.x += s.x;
		}
		if (error[1] <= d.x)
		{
			error[0] += d.x;
			curr.y += s.y;
		}
	}
}

/* Utilise l'algorithme de Bresenham pour dessiner un ligne */
void	draw_line(t_pixel *img, t_point p1, t_point p2)
{
	t_point	s;

	s.x = 1;
	s.y = 1;
	if (p1.x > p2.x)
		s.x = -1;
	if (p1.y > p2.y)
		s.y = -1;
	algorithm(img, p1, p2, s);
}
