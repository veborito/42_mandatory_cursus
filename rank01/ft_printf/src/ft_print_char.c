/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:53:41 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/01 20:01:16 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_char(int c)
{
	char	ch;
	int		len;	

	ch = c;
	len = 0;
	write(1, &ch, 1);
	len++;
	return (len);
}