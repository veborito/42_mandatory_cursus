/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:02:05 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/20 13:07:34 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	my_atoi(char *str)
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

int	my_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
