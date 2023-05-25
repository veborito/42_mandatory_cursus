/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:05:56 by bverdeci          #+#    #+#             */
/*   Updated: 2023/05/25 19:04:19 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		if ((str[i] == '+' && str[i]) || (str[i] == '-' && str[i]))
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res += str[i] - 48;
		i++;
		if (str[i] >= '0' && str[i] <= '9' && str[i])
			res *= 10;
	}
	return (res * sign);
}

long	ft_atoil(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		if ((str[i] == '+' && str[i]) || (str[i] == '-' && str[i]))
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res += str[i] - 48;
		i++;
		if (str[i] >= '0' && str[i] <= '9' && str[i])
			res *= 10;
	}
	return (res * sign);
}

static int	is_in(const char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	get_index(const char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[0] == '0')
		i++;
	while (!is_in(base, str[i]))
		i++;
	while (is_in(base, str[i]))
	{
		res += get_index(base, str[i]);
		i++;
		if (is_in(base, str[i]) && str[i])
			res *= ft_strlen(base);
	}
	return (res * sign);
}
