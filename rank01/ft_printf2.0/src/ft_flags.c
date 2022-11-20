/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:56:37 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/19 20:03:41 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putflag(int ch, t_data *frame)
{
	if (ch == 's')
		frame->width = frame->width - ft_strlen(frame->va) + 1;
	while (frame->width > 0)
	{
		ft_putchar(' ', frame);
		(frame->width)--;
	}
}

void	ft_width(const char *fmt, t_data *frame, int *i)
{
	int		len;
	int		j;
	int		k;
	char	*nb;

	len = 0;
	j = -1;
	while (ft_isdigit(fmt[++j]))
		len++;
	nb = malloc(sizeof(char) * (len + 1));
	if (nb == NULL)
		return ;
	j = 0;
	k = 0;
	while (ft_isdigit(fmt[j]))
		nb[k++] = fmt[j++];
	nb[k] = '\0';
	frame->width = ft_atoi(nb) - 1;
	free(nb);
	while (len > 0)
	{
		(*i)++;
		len--;
	}
}
