/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:35:59 by bverdeci          #+#    #+#             */
/*   Updated: 2022/11/23 09:17:09 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 5

typedef struct s_list	t_list;

struct s_list
{
	char	*content;
	t_list	*next;
};

char	*get_next_line(int fd);
void	ft_read_add(int fd, t_list **stock, int *output);
int		ft_in_list(t_list *stock, int c);
size_t	ft_strlen(const char *s);
t_list	*ft_lstlast(t_list *stock);
void	ft_lstadd_back(t_list **stock, char *buff);
size_t	ft_lst_strlen(t_list *lst);
void	ft_lst_toline(t_list *stock, char **line);

#endif
