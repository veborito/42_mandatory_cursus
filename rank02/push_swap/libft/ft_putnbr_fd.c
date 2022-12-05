/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:56:57 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/24 17:13:31 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	nb;

	nb = (long long int)n;
	if (nb < 0)
	{
		nb *= -1;
		write(fd, "-", 1);
	}
	if (nb >= 0 && nb <= 9)
	{
		nb += 48;
		write(fd, &nb, 1);
	}
	else
	{
		ft_putnbr_fd((nb / 10), fd);
		nb = (nb % 10) + 48;
		write(fd, &nb, 1);
	}
}
