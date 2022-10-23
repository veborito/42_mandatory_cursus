/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:13:12 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/23 16:44:04 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	size_t	my_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	int		len;
	char	ch;

	str = (char *)s;
	ch = c;
	len = my_strlen(s);
	i = len - 1;
	if (ch == '\0')
		return (&str[len]);
	while (i >= 0)
	{
		if (str[i] == ch)
			return (&str[i]);
		i--;
	}
	return (0);
}
