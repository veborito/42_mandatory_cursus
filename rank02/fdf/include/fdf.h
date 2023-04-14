/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:59:07 by bverdeci          #+#    #+#             */
/*   Updated: 2023/04/13 19:27:42 by bverdeci         ###   ########.fr       */
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

// LISTE UTILS
t_pointList	*ft_pointlast(t_pointList *lst);
t_pointList	*ft_pointnew(t_point *point);
void		ft_pointadd_back(t_pointList **lst, t_pointList *new_el);

#endif