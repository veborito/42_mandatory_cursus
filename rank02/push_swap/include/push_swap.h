/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:19:38 by bverdeci          #+#    #+#             */
/*   Updated: 2023/03/31 12:51:41 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// includes

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

// macros
# define INT_MIN -2147483648
# define INT_MAX 2147483647

//structs
typedef struct s_min_pos
{
	int	min;
	int	pos;
}		t_min_pos;
typedef struct s_num_pos
{
	int	num;
	int	pos;
}		t_num_pos;

//decla d'une liste chainnee pour le resultat

typedef struct s_result
{
	char			*operation;
	struct s_result	*next;
}					t_result;

// utils
t_list		*ft_before_last(t_list *stack);
void		ft_printlst(t_list *lst);
int			ft_lenstring_tab(char **stab);
void		ft_clearlst(t_list **stack);
t_result	*ft_lstnew_2(char *str);
int			ft_res_size(t_result *lst);
void		ft_lstadd_back_2(t_result **lst, t_result *new_el);
void		ft_printres(t_result *lst);
void		ft_clearres(t_result **res);
t_min_pos	ft_minimum(t_list *stk_a);
int			ft_findspace(char *str);
void		ft_normalize(t_list *s);
void		ft_remove_fromlst(t_list **s, int n);
int			ft_is_sorted_a(t_list *s);

// instructions
int			ft_initialize_stack(char **av, int ac, t_list **stack_a);
char		*ft_swap_a(t_list **stack);
char		*ft_swap_b(t_list **stack);
char		*ft_rotate_a(t_list **stack);
char		*ft_rotate_b(t_list **stack);
char		*ft_reverse_rotate_a(t_list **stack);
char		*ft_reverse_rotate_b(t_list **stack);
char		*ft_push_a(t_list **stack_b, t_list **stack_a);
char		*ft_push_b(t_list **stack_a, t_list **stack_b);

// sorting algo
void		ft_sort3(t_list **s, t_result **res);
void		ft_sort5(t_list **s_a, t_list **s_b, t_result **res);
void		ft_sort(t_list **s_a, t_list **s_b, t_result **res);
#endif
