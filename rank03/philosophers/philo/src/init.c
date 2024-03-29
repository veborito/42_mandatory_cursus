/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:11:00 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/29 14:17:49 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philos(t_philo **philos, t_table *table, int n_philo)
{
	int		i;
	t_philo	*temp;

	i = -1;
	while (++i < n_philo)
	{
		if (add_philo(philos, table, i) == 1)
			return (1);
	}
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
	return (0);
}

int	init_table(t_table *table, t_philo **philos, char **av)
{
	int				n_philo;

	n_philo = my_atoi(av[1]);
	if (init_philos(philos, table, n_philo) == 1)
		return (1);
	table->foods = INT_MAX;
	if (av[5])
		table->foods = my_atoi(av[5]);
	table->n_philo = n_philo;
	table->philos = *philos;
	table->t_die = (long int)my_atoi(av[2]);
	table->t_eat = (long int)my_atoi(av[3]);
	table->t_sleep = (long int)my_atoi(av[4]);
	table->done_eating = 0;
	table->status = ALIVE;
	if (pthread_mutex_init(&table->done_eating_m, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->status_m, NULL) != 0)
		return (1);
	return (0);
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

int	init_prog(int ac, char **av, t_philo **philos, t_table *table)
{
	if (ac < 5 || ac > 6)
	{
		write_error("Mauvais nombre d'arguments");
		return (1);
	}
	if (!check_args(av))
	{
		write_error("Mauvais arguments");
		return (1);
	}
	if (init_table(table, philos, av))
	{
		write_error("Initialization error");
		return (1);
	}
	table->t1 = get_time();
	return (0);
}
