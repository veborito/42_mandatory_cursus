/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:02:22 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/02 02:03:37 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>

void	ft_find_format(const char *str, size_t *i, va_list *args, int *len)
{
	if (str[*i] != '%')
		*len += ft_print_char(str[*i]);
	if (str[*i] == '%')
	{
		if (str[*i + 1] == 'c')
			*len += ft_print_char(va_arg(*args, int));
		if (str[*i + 1] == 's')
			*len += ft_print_string(va_arg(*args, char *));
		if (str[*i + 1] == 'p')
			ft_print_hexa_p(va_arg(*args, unsigned long), len);
		if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
			*len += ft_print_integer(va_arg(*args, int));
		if (str[*i + 1] == 'u')
			ft_print_unsigned(va_arg(*args, unsigned), len);
		if (str[*i + 1] == 'x')
			ft_print_hexa_min(va_arg(*args, unsigned int), len);
		if (str[*i + 1] == 'X')
			ft_print_hexa_maj(va_arg(*args, unsigned int), len);
		if (str[*i + 1] == '%')
			*len += ft_print_char(str[*i + 1]);
		(*i)++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		length;

	va_start(args, str);
	i = 0;
	length = 0;
	while (str[i])
	{
		ft_find_format(str, &i, &args, &length);
		i++;
	}
	va_end(args);
	return (length);
}
