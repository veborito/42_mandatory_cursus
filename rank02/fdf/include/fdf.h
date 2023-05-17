/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:59:07 by bverdeci          #+#    #+#             */
/*   Updated: 2023/04/14 16:37:39 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>

/* -------- CONSTANTES -------- */

# define WIDTH 1440
# define HEIGHT 720

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

// BRESENHAM
void		draw(t_pixel *img, t_point p1, t_point p2);

// LISTE UTILS
t_pointList	*pointlast(t_pointList *lst);
t_pointList	*pointnew(t_point *point);
void		pointadd_back(t_pointList **lst, t_pointList *new_el);

// TABS UTILS
int			strtab_len(char **s);
void		strtab_clear(char **s);
int			matrix_len(int **matrix);
int			tab_len(int	*tab);
void		add_to_tab(int *tab, char **s);

#endif