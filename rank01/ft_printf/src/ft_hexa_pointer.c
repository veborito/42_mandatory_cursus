/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:31:03 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/21 19:18:03 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putpointer(unsigned long int pointer, t_data *frame)
{
	char				*base;
	unsigned long int	nb;

	base = ft_strdup("0123456789abcdef");
	if (base == NULL)
		return ;
	if (pointer >= 0 && pointer <= 15)
	{
		ft_putstr("0x", frame);
		nb = base[pointer];
		ft_putchar(nb, frame);
	}
	else
	{
		ft_putpointer(pointer / 16, frame);
		nb = base[pointer % 16];
		ft_putchar(nb, frame);
	}
	free(base);
}

void	ft_hexa_min(unsigned int pointer, t_data *frame)
{
	char			*base;
	unsigned int	nb;

	base = ft_strdup("0123456789abcdef");
	if (base == NULL)
		return ;
	if (pointer >= 0 && pointer <= 15)
	{
		nb = base[pointer];
		ft_putchar(nb, frame);
	}
	else
	{
		ft_hexa_min(pointer / 16, frame);
		nb = base[pointer % 16];
		ft_putchar(nb, frame);
	}
	free(base);
}

void	ft_hexa_maj(unsigned int pointer, t_data *frame)
{
	char			*base;
	unsigned int	nb;

	base = ft_strdup("0123456789ABCDEF");
	if (base == NULL)
		return ;
	if (pointer >= 0 && pointer <= 15)
	{
		nb = base[pointer];
		ft_putchar(nb, frame);
	}
	else
	{
		ft_hexa_maj(pointer / 16, frame);
		nb = base[pointer % 16];
		ft_putchar(nb, frame);
	}
	free(base);
}
