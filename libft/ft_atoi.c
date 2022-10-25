/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:05:56 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/25 11:56:35 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i - 2] == '+' || str[i - 2] == '-')
		return (0);
	sign = 1;
	if (str[i - 1] == '-')
		sign = -1;
	res = 0;
	while (str[i] > '0' && str[i] <= '9')
	{
		res += str[i] - 48;
		if (str[i + 1] > '0' && str[i + 1] <= '9')
			res *= 10;
		i++;
	}
	return (res * sign);
}
