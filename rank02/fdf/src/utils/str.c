/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:30:53 by bverdeci          #+#    #+#             */
/*   Updated: 2023/05/25 19:31:27 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*str_upper(char *str)
{
	char	*upper;
	int		i;

	upper = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!upper)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			upper[i] = ft_toupper(str[i]);
		else
			upper[i] = str[i];
		i++;
	}
	return (upper);
}
