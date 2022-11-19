/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:56:37 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/19 19:56:50 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_width(const char *fmt, t_data *frame, int *i)
{
	int		len;
	int		j;
	int		k;
	char	*nb;

	len = 0;
	j = -1;
	while (ft_isdigit(fmt[++j]))
		len++;
	nb = malloc(sizeof(char) * (len + 1));
	if (nb == NULL)
		return ;
	j = 0;
	k = 0;
	while (ft_isdigit(fmt[j]))
		nb[k++] = fmt[j++];
	nb[k] = '\0';
	frame->width = ft_atoi(nb) - 1;
	free(nb);
	while (len > 0)
	{
		(*i)++;
		len--;
	}
}
