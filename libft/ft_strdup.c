/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:00:44 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/23 04:22:34 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s_copy;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	s_copy = (char *)malloc(sizeof(char) * (i + 1));
	if (!s_copy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s_copy[i] = s1[i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}
