/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:14:58 by bverdeci          #+#    #+#             */
/*   Updated: 2023/03/31 10:53:17 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n, t_data *frame)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		ft_putchar('-', frame);
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48, frame);
	else
	{
		ft_putnbr(nb / 10, frame);
		ft_putchar((nb % 10) + 48, frame);
	}
}

void	ft_putunsigned(unsigned int n, t_data *frame)
{
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48, frame);
	else
	{
		ft_putunsigned(n / 10, frame);
		ft_putchar((n % 10) + 48, frame);
	}
}
