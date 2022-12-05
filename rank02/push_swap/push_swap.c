/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:20:31 by bverdeci          #+#    #+#             */
/*   Updated: 2022/12/05 23:44:51 by bverdeci         ###   ########.fr       */
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
				return(1);
			checker = checker->next;
		}
		curr = curr->next;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	//t_list	*stack_b;
	int		initialized;

	stack_a = NULL;
	//stack_b = NULL;
	initialized = ft_initialize_stack(av, ac, &stack_a);
	if (initialized == -1 || ft_doublons(stack_a))
	{
		ft_printf("Error\n");
		exit (0);
	}
	ft_printlst(stack_a);
	ft_printf("\n\n");
	ft_sort3(&stack_a);
	ft_printf("\n\n");
	ft_printlst(stack_a);
	return (0);
}
