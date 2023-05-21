/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:59:07 by bverdeci          #+#    #+#             */
/*   Updated: 2023/05/20 12:43:02 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>

/* -------- CONSTANTES -------- */

# define WIDTH 1440
# define HEIGHT 720
# define ECART 5

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
	int		x;
	int		y;
	int		z;
}				t_point;

// LISTE DE COORDONNÉES
typedef struct s_pointList {
	t_point				point;
	struct s_pointList	*next;
	struct s_pointList	*prev;
}				t_pointList;

/* -------- FONCTIONS -------- */

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
void		clear_map(char ***map);

#endif