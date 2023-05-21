/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:58:46 by bverdeci          #+#    #+#             */
/*   Updated: 2023/05/20 14:47:47 by bverdeci         ###   ########.fr       */
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

void	throw_error(void)
{
	perror("Error ");
	exit(1);
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
		map = realloc_strtab(map, ft_split(ft_strtrim(line, "\n"), ' '), size);
		if (!map)
			throw_error();
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}

int	main(int ac, char **av)
{
	char	***map;
	int		i;
	int		j;

	if (ac == 2)
	{
		i = 0;
		map = create_map(av);
		while (map[i])
		{
			j = 0;
			while (map[i][j])
			{
				printf("%s ", map[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
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
