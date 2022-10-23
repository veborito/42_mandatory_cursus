/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:58:47 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/22 17:45:00 by bverdeci         ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ldst;
	size_t	lsrc;

	ldst = my_strlen(dst);
	lsrc = my_strlen(src);
	i = ldst;
	if (ldst < dstsize)
	{
		while (*src && (i < dstsize - 1))
		{
			dst[i] = *src;
			src++;
			i++;
		}
	}
	if (dstsize > 0 && ldst <= dstsize)
	{
		dst[i] = '\0';
		return (ldst + lsrc);
	}
	else
		return (lsrc + dstsize);
}
