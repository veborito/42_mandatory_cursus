/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:58:47 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/13 23:41:55 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	x = i - 1;
	if (i < dstsize)
	{
		while (src[j])
		{
			if (j < dstsize - (i + 1))
				dst[i + j] = src[j];
			j++;
		}
		return (i + j);
	}
	return (x + dstsize);
}
