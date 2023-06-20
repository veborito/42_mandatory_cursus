/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:34:46 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/20 12:44:51 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	my_strlen(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		continue ;
	return (i);
}

void	write_error(char *s)
{
	int	len;

	if (!s)
		return ;
	len = my_strlen(s);
	if (write(2, s, len) == -1 || write(2, "\n", 1) == -1)
		return ;
}
