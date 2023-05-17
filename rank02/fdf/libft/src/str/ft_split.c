/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:54:14 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/26 23:43:17 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static void	ft_free(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
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

static size_t	nbel(char const *str, char c, int *j, int *k)
{
	size_t	i;
	size_t	x;
	size_t	nbel;

	i = 0;
	nbel = 0;
	*j = 0;
	*k = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		x = i;
		while (str[i] != c && str[i])
			i++;
		if (i > x)
			nbel++;
	}
	return (nbel);
}

static void	get_size(char const *s, char c, int *i, int *start )
{
	while (s[*i] == c && s[*i])
	(*i)++;
	*start = *i;
	while (s[*i] != c && s[*i])
		(*i)++;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		start;
	int		k;

	split = (char **)malloc(sizeof(char *) * (nbel(s, c, &i, &k) + 1));
	if (!split || !s)
		return (NULL);
	while (i <= (int)ft_strlen(s))
	{
		get_size(s, c, &i, &start);
		if (i > start)
		{
			split[k] = my_strdup(s, start, i);
			if (!split[k])
			{
				ft_free(split);
				return (NULL);
			}
			k++;
		}
		i++;
	}
	split[k] = NULL;
	return (split);
}
