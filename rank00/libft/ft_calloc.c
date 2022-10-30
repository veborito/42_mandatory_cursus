/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:09:29 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/25 15:43:12 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*var;
	size_t	i;
	size_t	length;

	length = size * count;
	var = malloc(length);
	if (!var)
		return (NULL);
	i = 0;
	while (i < length)
	{
		var[i] = 0;
		i++;
	}
	return (var);
}
