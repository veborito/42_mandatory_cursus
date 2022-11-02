/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:34:27 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/02 01:07:24 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

void	ft_print_unsigned(unsigned int nb, int *len)
{
	char	c;

	if (nb >= 0 && nb <= 9)
	{
		c = nb + 48;
		write(1, &c, 1);
	}
	if (nb > 9)
	{
		ft_print_unsigned(nb / 10, len);
		nb = nb % 10;
		c = nb + 48;
		write(1, &c, 1);
		(*len)++;
	}
}

int	ft_print_integer(int nb)
{
	char	*number;
	int		len;

	number = ft_itoa(nb);
	if (!number)
		return (0);
	write(1, number, ft_strlen(number));
	len = ft_strlen(number);
	free(number);
	return (len);
}
