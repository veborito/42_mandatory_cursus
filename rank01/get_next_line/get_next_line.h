/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:37:28 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/10 00:44:05 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
int		ft_is_in(char *s);
int		ft_count_from_list(t_list *stock);
void	ft_clearlst(t_list **stock);
void	ft_read_and_add(int fd, t_list **stock, int *output);
void	ft_add_link(t_list **stock, char *buff);
t_list	*ft_lstlast(t_list *stock);
void	ft_add_from_list(t_list *stock, char *line);
void	ft_update_stock(t_list **stock);
size_t	ft_strlen(char *s);

#endif
