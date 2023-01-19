/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:27:05 by bverdeci          #+#    #+#             */
/*   Updated: 2022/12/16 18:34:30 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//buffer size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

//includes
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

//fonctions
char	*get_next_line(int fd);
int		ft_find_nl(char *s);
int		ft_len(char *s);
char	*ft_add_and_free(char *stock, char *buff);

#endif