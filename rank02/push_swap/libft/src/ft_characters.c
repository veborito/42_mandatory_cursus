/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_characters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:30:12 by bverdeci          #+#    #+#             */
/*   Updated: 2022/12/01 12:09:11 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putchar(int c, t_data *frame)
{
	if (write (1, &c, 1) == -1)
	{
		frame->error = 1;
		return ;
	}
	++(frame->len);
}

void	ft_putstr(char *s, t_data *frame)
{
	int	len;

	if (s == NULL)
	{
		len = ft_strlen("(null)");
		if (write(1, "(null)", len) == -1)
			frame->error = 1;
		else
			frame->len += len;
		return ;
	}
	len = ft_strlen(s);
	if (write (1, s, len) == -1)
	{
		frame->error = 1;
		return ;
	}
	frame->len += len;
}
