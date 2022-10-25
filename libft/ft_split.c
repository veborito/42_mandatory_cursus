/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:54:14 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/24 01:44:55 by bverdeci         ###   ########.fr       */
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

static	int	is_in(char const s, char c)
{
	int	flag;

	flag = 0;
	if (s == c)
		flag = 1;
	return (flag);
}

static char	*my_strdup(const char *s1, size_t start, size_t end)
{
	char	*s_copy;
	size_t	i;
	size_t	j;

	s_copy = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!s_copy)
		return (NULL);
	i = start;
	j = 0;
	while (i < end)
	{
		s_copy[j] = s1[i];
		i++;
		j++;
	}
	s_copy[j] = '\0';
	return (s_copy);
}

static size_t	nbel(char const *str, char c)
{
	size_t	i;
	size_t	x;
	size_t	nbel;

	i = 0;
	nbel = 0;
	while (str[i])
	{
		while (is_in(str[i], c) && str[i])
			i++;
		x = i;
		while (!(is_in(str[i], c)) && str[i])
			i++;
		if (i > x)
			nbel++;
	}
	return (nbel);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	start;
	size_t	k;

	split = (char **)malloc(sizeof(char *) * (nbel(s, c) + 1));
	if (!split || !s)
		return (NULL);
	i = 0;
	k = 0;
	while (i <= my_strlen(s))
	{
		while (is_in(s[i], c) && s[i])
			i++;
		start = i;
		while (!(is_in(s[i], c)) && s[i])
			i++;
		if (i > start)
			split[k++] = my_strdup(s, start, i);
		i++;
	}
	split[k] = NULL;
	return (split);
}
