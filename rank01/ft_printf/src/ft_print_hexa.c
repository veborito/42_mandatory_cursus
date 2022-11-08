/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:44:01 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/08 16:31:00 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_print_hexa_maj(unsigned int n, int *len)
{
	char	*base;

	base = ft_strdup("0123456789ABCDEF");
	if (n >= 0 && n <= 15)
	{
		write(1, &base[n], 1);
		(*len)++;
	}
	else if (n > 15)
	{
		ft_print_hexa_maj(n / 16, len);
		n = n % 16;
		write(1, &base[n], 1);
		(*len)++;
	}
	free(base);
}

void	ft_print_hexa_min(unsigned int n, int *len)
{
	char	*base;

	base = ft_strdup("0123456789abcdef");
	if (n >= 0 && n <= 15)
	{
		write(1, &base[n], 1);
		(*len)++;
	}
	else if (n > 15)
	{
		ft_print_hexa_min(n / 16, len);
		n = n % 16;
		write(1, &base[n], 1);
		(*len)++;
	}
	free(base);
}

void	ft_print_hexa_p(unsigned long n, int *len)
{
	char	*base;

	base = ft_strdup("0123456789abcdef");
	if (n >= 0 && n <= 15)
	{
		write(1, "0x", 2);
		write(1, &base[n], 1);
		*len += 3;
	}
	else if (n > 15)
	{
		ft_print_hexa_p(n / 16, len);
		n = n % 16;
		write(1, &base[n], 1);
		(*len)++;
	}
	free(base);
}
