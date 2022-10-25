/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:32:24 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/23 20:35:47 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	my_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static	int	is_in(char c, char const *set)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (set[i])
	{
		if (set[i] == c)
			flag = 1;
		i++;
	}
	return (flag);
}

static	size_t	get_start(char const *s, char const *set)
{
	size_t	i;

	i = 0;
	while (is_in(s[i], set) && s[i])
		i++;
	return (i);
}

static	size_t	get_end(char const *s, char const *set)
{
	size_t	i;

	i = my_strlen(s) - 1;
	while (is_in(s[i], set))
		i--;
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	i = get_start(s1, set);
	j = get_end(s1, set);
	if (j > i)
	{
		str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (!str)
			return (NULL);
	}
	else
		str = (char *)malloc(sizeof(char) * 1);
	k = 0;
	while (i < j)
	{
		str[k] = s1[i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}
