/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:46:08 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/02 01:01:20 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(int c);
int		ft_print_integer(int nb);
void	ft_print_unsigned(unsigned int nb, int *len);
int		ft_print_string(char *s);
void	ft_print_hexa_p(unsigned long n, int *len);
void	ft_print_hexa_maj(unsigned int n, int *len);
void	ft_print_hexa_min(unsigned int n, int *len);

#endif
