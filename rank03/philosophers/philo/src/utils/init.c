/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:11:00 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/21 14:23:03 by bverdeci         ###   ########.fr       */
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
	table->philos = *philos;
	table->t_die = (long int)my_atoi(av[2]);
	table->t_eat = (long int)my_atoi(av[3]);
	table->t_sleep = (long int)my_atoi(av[4]);
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