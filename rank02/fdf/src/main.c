/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:58:46 by bverdeci          #+#    #+#             */
/*   Updated: 2023/04/14 15:41:28 by bverdeci         ###   ########.fr       */
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

/* Utilise l'algorithme de Bresenham pour dessiner un ligne */
void	draw(t_pixel *img, t_point p1, t_point p2)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;

	x = p1.x;
	y = p1.y;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	p = 2 * dy - dx;
	while (x <= p2.x)
	{
		my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
		x++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			y--;
		}
	}
}

void	clear_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

int	strtab_len(char **s)
{
	int	len;
	
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	matrix_len(int **matrix)
{
	int	len;

	len = 0;
	while (matrix[len])
		len++;
	return (len);
}

int		**copy_tab(int **matrix)
{
	int	**new_m;
	int	*tab;
	int	len;
	int	i;
	int	j;
	len = matrix_len(matrix);
	new_m = malloc(sizeof(int *) * len);
	if(!new_m)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		j = 0;
		len = tab_len(matrix[i]);
		tab = malloc(sizeof(int) * len);
		while(matrix[i][j])
		{
			tab[j] = matrix[i][j]
		}
	}
	
}

int	add_to_tab(char **s, int **matrix, int *i)
{
	int	len;
	int	*tab;
	int	**temp;

	len = strtab_len(s);
	temp = copy_tab(matrix);
	matrix = malloc(sizeof(*int) + i);
	if (!matrix)
		return ;
	
}

int	**parse_arg(char **av, int fd)
{
	char	*line;
	char	**line_split;
	int		**matrix;
	int		i;
	
	line = get_next_line(fd);
	matrix = NULL;
	while (line != NULL)
	{
		line = get_next_line(fd);
		line_split = ft_split(line, ' ');
		if (add_to_tab(line_split, matrix) != 0)
			return (NULL);		
		clear_split(line_split);
	}
}

void	throw_error(int error)
{
	perror("Error ");
	exit(1)
}
int	main(int ac, char **av)
{
	int		fd;
	int		**map;
	void	*mlx;
	void	*mlx_win;
	t_pixel	img;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY, S_IRUSR | S_IWUSR);
		if (fd == -1)
		{
			perror("Error ");
			exit(1);
		}	
		map = parse_arg(av, fd);
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "FIL DE FER");
		img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
		exit(0);
	}
}
