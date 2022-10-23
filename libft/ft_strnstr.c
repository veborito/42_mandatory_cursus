/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:39:41 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/23 05:38:49 by bverdeci         ###   ########.fr       */
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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	x;

	k = 0;
	i = 0;
	if (needle[0] == 0)
		return (&((char *)haystack)[0]);
	x = my_strlen(needle);
	while (i < len && haystack[k])
	{
		i = k;
		j = 0;
		while (haystack[i] == needle[j] && haystack[i] && i < len)
		{
			i++;
			j++;
		}
		if (j == x)
			return (&((char *)haystack)[i - j]);
		k++;
	}
	return (0);
}
