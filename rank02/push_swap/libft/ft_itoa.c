/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:03:51 by bverdeci          #+#    #+#             */
/*   Updated: 2022/12/01 12:08:26 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	nbel(int n)
{
	size_t			tot;
	long long int	nb;

	tot = 0;
	nb = (long long int) n;
	if (n < 0 || n == 0)
	{
		tot++;
		nb *= -1;
	}
	while (nb > 0)
	{
		if (nb >= 0 && nb <= 9)
		{
			tot++;
			nb -= nb;
		}
		else
		{	
			nb /= 10;
			tot++;
		}
	}
	return (tot);
}

static char	*ft_putnb(int n, char *s)
{
	size_t			i;
	long long int	nb;

	i = nbel(n) - 1;
	nb = (long long int)n;
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		if (nb >= 0 && nb <= 9)
		{
			s[i] = nb + 48;
			nb -= nb;
			i--;
			if (n < 0)
				s[i] = '-';
		}
		else
		{
			s[i] = (nb % 10) + 48;
			nb /= 10;
			i--;
		}
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * (nbel(n) + 1));
	if (!s)
		return (NULL);
	if (n == 0)
		s[nbel(n) - 1] = '0';
	else
		ft_putnb(n, s);
	s[nbel(n)] = '\0';
	return (s);
}
