/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:27:41 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/23 02:16:42 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*ndst;
	const char	*nsrc;

	i = 0;
	ndst = (char *)dst;
	nsrc = (const char *)src;
	if (dst == 0 && src == 0)
		return (0);
	if (dst < src)
	{
		while (i < len)
		{
			ndst[i] = nsrc[i];
			i++;
		}
	}
	else
	{
		while (len--)
		{
			ndst[len] = nsrc[len];
		}
	}
	return (dst);
}
