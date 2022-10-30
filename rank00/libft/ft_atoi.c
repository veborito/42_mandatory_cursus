/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:05:56 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/25 14:49:14 by bverdeci         ###   ########.fr       */
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
