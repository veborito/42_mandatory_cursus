/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:59:07 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/01 15:20:06 by bverdeci         ###   ########.fr       */
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

// TRANSFO
void		iso_transfo(int *x, int *y, int z);




// EVENTS
int			close_win(t_fdf *fdf);
int			key_event(int keycode, t_fdf *fdf);


//EVENTS ENUM
enum e_events {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// KEYS ENUM
enum e_keycode
{
	KEYCODE_A = 0,
	KEYCODE_S = 1,
	KEYCODE_D = 2,
	KEYCODE_F = 3,
	KEYCODE_H = 4,
	KEYCODE_G = 5,
	KEYCODE_Y = 6,
	KEYCODE_X = 7,
	KEYCODE_C = 8,
	KEYCODE_V = 9,
	KEYCODE_RAN = 10,
	KEYCODE_B = 11,
	KEYCODE_Q = 12,
	KEYCODE_W = 13,
	KEYCODE_E = 14,
	KEYCODE_R = 15,
	KEYCODE_Z = 18,
	KEYCODE_T = 17,
	KEYCODE_1 = 18,
	KEYCODE_2 = 19,
	KEYCODE_3 = 20,
	KEYCODE_4 = 21,
	KEYCODE_6 = 22,
	KEYCODE_5 = 23,
	KEYCODE_9 = 25,
	KEYCODE_7 = 26,
	KEYCODE_8 = 28,
	KEYCODE_0 = 29,
	KEYCODE_O = 31,
	KEYCODE_I = 34,
	KEYCODE_L = 37,
	KEYCODE_K = 40,
	KEYCODE_TAB = 49,
	KEYCODE_SPACE = 49,
	KEYCODE_ESC = 53,
	KEYCODE_LEFT_ARROW = 123,
	KEYCODE_RIGHT_ARROW = 124,
	KEYCODE_DOWN_ARROW = 125,
	KEYCODE_UP_ARROW = 126,
	KEYCODE_LSHIFT = 257,
	KEYCODE_RSHIFT = 258,
};


#endif
