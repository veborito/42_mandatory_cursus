/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:20:31 by bverdeci          #+#    #+#             */
/*   Updated: 2023/02/17 17:40:33 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_doublons(t_list *stack)
{
	t_list	*curr;
	t_list	*checker;

	curr = stack;
	while (curr != NULL)
	{
		checker = stack;
		while (checker != NULL)
		{
			if (checker != curr && curr->content == checker->content)
				return (1);
			checker = checker->next;
		}
		curr = curr->next;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_result	*res;
	int			initialized;

	if (ac == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	stack_a = NULL;
	stack_b = NULL;
	res = NULL;
	initialized = ft_initialize_stack(av, ac, &stack_a);
	if (initialized == -1 || ft_doublons(stack_a))
	{
		if (stack_a)
			ft_clearlst(&stack_a);
		write(2, "Error\n", 6);
		exit(1);
	}
	if (ft_lstsize(stack_a) == 1)
	{
		ft_clearlst(&stack_a);
		exit(1);
	}
	else if (ft_lstsize(stack_a) <= 3)
		ft_sort3(&stack_a, &res);
	else if (ft_lstsize(stack_a) > 3 && ft_lstsize(stack_a) <= 5)
		ft_sort5(&stack_a, &stack_b, &res);
	ft_printres(res);
	//ft_printlst(stack_a);
	ft_clearlst(&stack_a);
	ft_clearres(&res);
	//check_leaks();
	sleep(100);
	return (0);
}
