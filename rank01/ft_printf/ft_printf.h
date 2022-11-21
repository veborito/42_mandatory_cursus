/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:07:50 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/21 20:49:02 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// includes
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
// definition of the struct 

typedef struct s_data
{
	va_list	va;
	va_list	va_copy;
	int		len;
}			t_data;

//definition of fonctions prototypes

int		ft_printf(const char *fmt, ...);
void	ft_putchar(int c, t_data *frame);
void	ft_initialize(t_data *frame);
void	ft_putstr(char *s, t_data *frame);
void	ft_putnbr(int n, t_data *frame);
void	ft_width(const char *fmt, t_data *frame, int *i);
void	ft_putpointer(unsigned long int pointer, t_data *frame);
void	ft_hexa_min(unsigned int pointer, t_data *frame);
void	ft_hexa_maj(unsigned int pointer, t_data *frame);
void	ft_putunsigned(unsigned int n, t_data *frame);
#endif
