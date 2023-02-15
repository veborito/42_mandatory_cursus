/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:23:53 by bverdeci          #+#    #+#             */
/*   Updated: 2023/02/15 15:27:30 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*check si l'argument est un nombre*/
static int	ft_check_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	ft_clear_numbers(char **numbers)
{
	int	i;

	i = 0;
	ft_printf("elle est ou la segfault\n");
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

/* initialisation de la stack A */

int	ft_initialize_stack(char **av, int ac, t_list **stack_a)
{
	int		i;
	char	**numbers;

	i = 1;
	if (ac == 1)
		return (-1);
	else if (ac == 2)
	{
		i = 0;
		numbers = ft_split(av[1], ' ');
		if (!numbers)
			return (-1);
	}
	else
		numbers = av;
	while (numbers[i])
	{
		if (ft_check_arg(numbers[i]))
			return (-1);
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(numbers[i])));
		i++;
	};
	if (ac == 2)
		ft_clear_numbers(numbers);
	return (ft_lstsize(*stack_a));
}
