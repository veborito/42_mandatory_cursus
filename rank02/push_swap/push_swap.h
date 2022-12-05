/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:19:38 by bverdeci          #+#    #+#             */
/*   Updated: 2022/12/05 23:40:34 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// includes

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

// utils
t_list	*ft_before_last(t_list *stack);
void	ft_printlst(t_list *lst);

// instructions
int		ft_initialize_stack(char **av, int ac, t_list **stack_a);
int		ft_swap_a(t_list **stack);
int		ft_swap_b(t_list **stack);
int		ft_rotate_a(t_list **stack);
int		ft_rotate_b(t_list **stack);
int		ft_reverse_rotate_a(t_list **stack);
int		ft_reverse_rotate_b(t_list **stack);
void	ft_push(t_list **stack_a, t_list **stack_b);

// sorting algo

void	ft_sort3(t_list **s);
#endif
