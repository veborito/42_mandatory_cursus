/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:59:07 by bverdeci          #+#    #+#             */
/*   Updated: 2023/05/26 17:04:06 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>

/* -------- CONSTANTES -------- */

# define WIDTH 1920
# define HEIGHT 1080
# define ECART 5
# define BASIC_COLOR 0x00FF0000

/* -------- STRUCTURES -------- */

// IMAGE
typedef struct s_pixel {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_pixel;

// COORDONNÉES
typedef struct s_point {
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

// LISTE DE COORDONNÉES
typedef struct s_pointList {
	t_point				point;
	struct s_pointList	*next;
	struct s_pointList	*prev;
}				t_pointList;

// SQUARE POINTS
typedef struct s_square {
	t_point				p1;
	t_point				p2;
	t_point				p3;
	t_point				p4;
}				t_square;

// FDF GIGA STRUCT
typedef struct s_fdf {
	void	*mlx;
	void	*mlx_win;
	char	***map;
	t_point	**p_map;
}				t_fdf;

/* -------- FONCTIONS -------- */

// ERROR
void		throw_error(void);

// DRAW
void		draw_line(t_pixel *img, t_point p1, t_point p2);
void		my_mlx_pixel_put(t_pixel *data, int x, int y, int color);

// LISTE UTILS
t_pointList	*pointlast(t_pointList *lst);
t_pointList	*pointnew(t_point *point);
void		pointadd_back(t_pointList **lst, t_pointList *new_el);

// TABS UTILS
int			strtab_len(char **s);
void		strtab_clear(char **s);
char		**copy_strtab(char **tab);

// MAP UTILS
void		clear_map(char ***map);
char		***copy_map(char ***map, int size);
char		***realloc_strtab(char ***map, char **row, int size);
char		***create_map(char **av);
int			map_len(char ***map);

// POINTS UTILS

void		add_point(t_point **p_map, char ***map, char **row, int line);
t_point		**p_create_map(char ***map);
t_point		set_point(t_point **p_map, int row, int col);

// STR UTILS
int			ft_in_str(char *str, char c);
char		*str_upper(char *str);

void		iso_transfo(int *x, int *y, int z);

#endif
