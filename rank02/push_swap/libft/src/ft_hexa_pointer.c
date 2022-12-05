/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:31:03 by bverdeci          #+#    #+#             */
/*   Updated: 2022/12/01 12:10:05 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putpointer(unsigned long int pointer, t_data *frame)
{
	char				*base;

	base = ft_strdup("0123456789abcdef");
	if (base == NULL)
		return ;
	if (pointer >= 0 && pointer <= 15)
	{
		ft_putstr("0x", frame);
		ft_putchar(base[pointer], frame);
	}
	else
	{
		ft_putpointer(pointer / 16, frame);
		ft_putchar(base[pointer % 16], frame);
	}
	free(base);
}

void	ft_hexa_min(unsigned int pointer, t_data *frame)
{
	char			*base;

	base = ft_strdup("0123456789abcdef");
	if (base == NULL)
		return ;
	if (pointer >= 0 && pointer <= 15)
		ft_putchar(base[pointer], frame);
	else
	{
		ft_hexa_min(pointer / 16, frame);
		ft_putchar(base[pointer % 16], frame);
	}
	free(base);
}

void	ft_hexa_maj(unsigned int pointer, t_data *frame)
{
	char			*base;

	base = ft_strdup("0123456789ABCDEF");
	if (base == NULL)
		return ;
	if (pointer >= 0 && pointer <= 15)
		ft_putchar(base[pointer], frame);
	else
	{
		ft_hexa_maj(pointer / 16, frame);
		ft_putchar(base[pointer % 16], frame);
	}
	free(base);
}
