/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:20:31 by bverdeci          #+#    #+#             */
/*   Updated: 2023/03/31 00:39:10 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted_a(t_list *s)
{
	while (s->next != NULL)
	{
		if (s->content > s->next->content)
			return (0);
		s = s->next;
	}
	return (1);
}

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

static void	ft_sorting(t_list **stack_a, t_list **stack_b, t_result **res)
{
	if (ft_lstsize(*stack_a) == 1)
	{
		ft_clearlst(stack_a);
		return ;
	}
	else if (ft_lstsize(*stack_a) <= 3)
		ft_sort3(stack_a, res);
	else if (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_a) <= 5)
		ft_sort5(stack_a, stack_b, res);
	else
		ft_sort(stack_a, stack_b, res);
}

static void	ft_error(t_list **stack_a, int initialized)
{
	if (initialized == -1 || ft_doublons(*stack_a))
	{
		if (*stack_a)
			ft_clearlst(stack_a);
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}

int	main(int ac, char *av[])
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_result	*res;
	int			initialized;

	if (ac == 1)
		exit(0);
	stack_a = NULL;
	stack_b = NULL;
	res = NULL;
	initialized = ft_initialize_stack(av, ac, &stack_a);
	ft_error(&stack_a, initialized);
	if (ft_is_sorted_a(stack_a))
	{
		ft_clearlst(&stack_a);
		exit(0);
	}
	ft_sorting(&stack_a, &stack_b, &res);
	ft_printres(res);
	ft_clearlst(&stack_a);
	ft_clearlst(&stack_b);
	ft_clearres(&res);
	exit(0);
}
