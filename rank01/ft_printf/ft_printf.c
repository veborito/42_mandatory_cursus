/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:21:18 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/21 21:04:45 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

void	ft_initialize(t_data *frame)
{
	frame->len = 0;
}

void	ft_format(char ch, t_data *frame)
{
	if (ch == '%')
		ft_putchar('%', frame);
	if (ch == 'c')
		ft_putchar(va_arg(frame->va, int), frame);
	if (ch == 's')
		ft_putstr(va_arg(frame->va, char *), frame);
	if (ch == 'd' || ch == 'i')
		ft_putnbr(va_arg(frame->va, int), frame);
	if (ch == 'u')
		ft_putunsigned(va_arg(frame->va, unsigned int), frame);
	if (ch == 'p')
		ft_putpointer(va_arg(frame->va, unsigned long int), frame);
	if (ch == 'x')
		ft_hexa_min(va_arg(frame->va, unsigned int), frame);
	if (ch == 'X')
		ft_hexa_maj(va_arg(frame->va, unsigned int), frame);
}

void	ft_iteration(t_data *frame, const char *fmt)
{
	int	i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			ft_format(fmt[i], frame);
		}
		else
			ft_putchar(fmt[i], frame);
		i++;
	}
}

int	ft_printf(const char *fmt, ...)
{
	t_data	*frame;
	int		res;

	frame = malloc(sizeof(t_data));
	if (frame == NULL || fmt == NULL)
		return (-1);
	ft_initialize(frame);
	va_start(frame->va, fmt);
	ft_iteration(frame, fmt);
	va_end(frame->va);
	res = frame->len;
	free(frame);
	return (res);
}
