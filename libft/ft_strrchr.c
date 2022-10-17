/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:13:12 by bverdeci          #+#    #+#             */
/*   Updated: 2022/10/16 22:36:39 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (s[i])
		i++;
	if (c == 0)
		return (&str[i]);
	while (str[i - 1])
	{
		if (str[i - 1] == c)
			return (&str[i - 1]);
		i--;
	}
	return (0);
}
