/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:39:41 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/17 19:39:50 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	if (haystack[i] == 0 && needle[i] == 0)
		return (&((char *)haystack)[i]);
	while (needle[i])
		i++;
	x = i;
	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		while (haystack[i] == needle[j] && haystack[i] && i < len)
		{
			j++;
			i++;
		}
		if (j == x)
			return (&((char *)haystack)[i - j]);
		i++;
	}
	return (0);
}
