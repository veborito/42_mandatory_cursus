/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:05:24 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/11 12:24:33 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	
	i = 0;
	while (i < len)
	{
		*((unsigned char*) b + i)  = (unsigned char) c;
		i++;
	}
	return (b);
}
