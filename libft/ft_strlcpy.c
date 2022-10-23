/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:56:22 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/21 18:35:24 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (dstsize && i < dstsize - 1)
		{
			dst[i] = src[i];
			j++;
		}
		i++;
	}
	if (dstsize == 0)
		return (i);
	else
		dst[j] = '\0';
	return (i);
}
