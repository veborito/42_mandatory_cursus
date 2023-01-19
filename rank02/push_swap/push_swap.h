/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:19:38 by bverdeci          #+#    #+#             */
/*   Updated: 2023/01/09 12:10:08 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// includes

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

//structs
typedef struct	s_min_pos
{
	int	min;
	int	pos;
}		t_min_pos;

// utils
t_list	*ft_before_last(t_list *stack);
void	ft_printlst(t_list *lst);
int		ft_lenstring_tab(char **stab);

// instructions
int		ft_initialize_stack(char **av, int ac, t_list **stack_a);
char	*ft_swap_a(t_list **stack);
char	*ft_swap_b(t_list **stack);
char	*ft_rotate_a(t_list **stack);
char	*ft_rotate_b(t_list **stack);
char	*ft_reverse_rotate_a(t_list **stack);
char	*ft_reverse_rotate_b(t_list **stack);
char	*ft_push_a(t_list **stack_a, t_list **stack_b);
char	*ft_push_b(t_list **stack_b, t_list **stack_a);


// sorting algo

int		ft_sort3(t_list **s);
int		ft_sort5(t_list **s_a, t_list **s_b);
#endif
