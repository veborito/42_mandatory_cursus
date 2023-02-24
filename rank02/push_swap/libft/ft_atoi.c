/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:05:56 by bverdeci          #+#    #+#             */
/*   Updated: 2023/02/24 13:54:42 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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