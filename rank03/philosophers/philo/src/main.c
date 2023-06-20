/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:57:34 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/20 16:47:12 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_philo **philos, t_table *table, int n_philo)
{
	int		i;
	t_philo	*temp;

	i = -1;
	while (++i < n_philo)
		add_philo(philos, table, i);
	temp = *philos;
	while (temp)
	{
		if (temp->next)
			temp->next_fork = &temp->next->fork;
		else
			temp->next_fork = &(*philos)->fork;
		temp = temp->next;
	}
	temp = *philos;
	while (temp)
	{
		printf("fork : %p  next_fork : %p\n", &temp->fork, temp->next_fork);
		temp = temp->next;
	}
}

void	init_table(t_table *table, t_philo **philos, char **av)
{
	int	n_philo;

	n_philo = my_atoi(av[1]);
	init_philos(philos, table, n_philo);
	(void)table;
}

int	check_args(char **av)
{
	int	i;
	int	j;

	i = 0;
	if (my_atoi(av[2]) == 0)
		return (0);
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!my_isdigit(av[i][j]))
				return (0);
		}
		if (my_atoi(av[i]) > INT_MAX || my_atoi(av[i]) < 0)
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_table	table;
	t_philo	*philos;

	memset(&table, 0, sizeof(table));
	philos = NULL;
	if (ac < 4 || ac > 5)
	{
		write_error("Mauvais nombre d'arguments");
		return (1);
	}
	if (!check_args(av))
	{
		write_error("Mauvais arguments");
		return (1);
	}
	init_table(&table, &philos, av);
	return (0);
}
