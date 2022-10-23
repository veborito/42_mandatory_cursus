/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:32:55 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/23 15:55:41 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	if (start < my_strlen(s))
	{
		if (len > my_strlen(s))
			len = my_strlen(s);
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		while (j < len && s[i])
		{
			str[j] = s[i];
			i++;
			j++;
		}
	}
	else
		str = (char *)malloc(sizeof(char) * 1);
	str[j] = '\0';
	return (str);
}
