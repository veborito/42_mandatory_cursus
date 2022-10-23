/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:32:55 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/21 00:44:42 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc(sizeof(str) * len);
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (j < len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	return (str);
}
