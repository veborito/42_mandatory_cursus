/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:09:29 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/23 15:15:49 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*var;
	size_t	i;

	var = (char *)malloc(size * count);
	if (!var)
		return (NULL);
	i = 0;
	while (var[i])
	{
		var[i] = 0;
		i++;
	}
	return (var);
}
