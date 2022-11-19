/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_characters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:30:12 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/19 17:43:42 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

void	ft_putchar(int c, t_data *frame)
{
	if (write (1, &c, 1) == -1)
	{
		frame->len = 0;
		return ;
	}
	++(frame->len);
}

void	ft_putstr(char *s, t_data *frame)
{
	int	len;

	len = ft_strlen(s);
	if (write (1, s, len) == -1)
	{
		frame->len = 0;
		return ;
	}
	frame->len += len;
}
