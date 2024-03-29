/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:23:53 by bverdeci          #+#    #+#             */
/*   Updated: 2023/03/31 12:40:01 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*check si l'argument est un nombre*/
static int	ft_check_arg(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	if (ft_atoil(str) > INT_MAX || ft_atoil(str) < INT_MIN)
		return (1);
	return (0);
}

static void	ft_clear_numbers(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

static int	ft_is_quote(char *str, t_list **stack_a)
{
	char	**temp;
	int		j;

	temp = ft_split(str, ' ');
	j = 0;
	while (temp[j])
	{
		if (ft_check_arg(temp[j]))
		{
			ft_clear_numbers(temp);
			return (-1);
		}
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(temp[j])));
		j++;
	}
	ft_clear_numbers(temp);
	return (0);
}

static int	ft_parse(char **numbers, t_list **stack_a, int *i, char **av)
{	
	while (numbers[*i])
	{
		if (ft_findspace(numbers[*i]))
		{
			if (ft_is_quote(numbers[*i], stack_a) == -1)
				return (-1);
		}
		else
		{
			if (ft_check_arg(numbers[*i]))
			{
				if (ft_findspace(av[1]))
					ft_clear_numbers(numbers);
				return (-1);
			}
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(numbers[*i])));
		}
		(*i)++;
	}
	return (0);
}

/* initialisation de la stack A */

int	ft_initialize_stack(char **av, int ac, t_list **stack_a)
{
	int		i;
	char	**numbers;

	i = 1;
	numbers = NULL;
	if (ac == 1)
		return (-1);
	else if (ac == 2 && ft_findspace(av[1]))
	{
		i = 0;
		numbers = ft_split(av[1], ' ');
		if (!numbers)
			return (-1);
	}
	else
		numbers = av;
	if (ft_parse(numbers, stack_a, &i, av) == -1)
		return (-1);
	else if (ac == 2 && ft_findspace(av[1]))
		ft_clear_numbers(numbers);
	ft_normalize(*stack_a);
	return (ft_lstsize(*stack_a));
}
