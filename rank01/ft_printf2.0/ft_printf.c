/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:21:18 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/19 19:57:28 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

void	ft_initialize(t_data *frame)
{
	frame->len = 0;
	frame->width = 0;
}

void	ft_flags(const char *fmt, t_data *frame, int *i)
{
	ft_width(fmt, frame, i);
}

void	ft_format(char ch, t_data *frame)
{
	if (ch == 's')
		frame->width = frame->width - ft_strlen(frame->va) + 1;
	while (frame->width > 0)
	{
		ft_putchar(' ', frame);
		(frame->width)--;
	}
	if (ch == 'c')
		ft_putchar(va_arg(frame->va, int), frame);
	if (ch == 's')
		ft_putstr(va_arg(frame->va, char *), frame);
	if (ch == 'd')
		ft_putnbr(va_arg(frame->va, int), frame);
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
			ft_flags(fmt + i, frame, &i);
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
		return (0);
	ft_initialize(frame);
	va_start(frame->va, fmt);
	va_copy(frame->va_copy, frame->va);
	ft_iteration(frame, fmt);
	va_end(frame->va);
	res = frame->len;
	free(frame);
	return (res);
}
