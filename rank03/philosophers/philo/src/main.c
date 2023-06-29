/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:57:34 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/29 12:45:05 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*  --- DEBUG -------

	t_philo *temp;

	temp = philos;
	while (temp)
	{
		printf("philo : %d -- table : %p -- fork : %p --\
 next_fork : %p -- status: %d\n",
			temp->id, temp->table, &temp->fork, temp->next_fork, temp->status);
		temp = temp->next;
	}
	printf("time to die: %d -- time to eat : %d -- time to sleep : %d\n", table.t_die, table.t_eat, table.t_sleep);
	printf("foods needed : %d\n", table.foods);
	printf("------------------------\n");
	printf("first philo : %d\n", table.philos->id);
*/

/*
----- TODO ------
- Creer la routine pour un philo
- faire une fonction pour sleep et checker si un philo meurs en meme temps qu'il fait une autre action.

*/

int create_philos(t_philo *philos)
{
    t_philo *temp;
    
    temp = philos;
    while (temp)
    {
        if (pthread_create(&philos->philo, 0, &routine, temp) == -1)
            return (1);
        temp = temp->next;
		ms_sleep(1);
    }
    temp = philos;
    while (temp)
    {
        if (pthread_join(philos->philo, NULL) == -1)
            return (1);
        temp = temp->next;
    }
    return (0);
}

void	destroy_philos(t_philo **philos)
{
	t_philo *tmp;

	while (philos)
	{
		pthread_mutex_destroy(&(*philos)->eat_m);
		pthread_mutex_destroy(&(*philos)->fork);
		pthread_mutex_destroy(&(*philos)->print_m);
		pthread_mutex_destroy(&(*philos)->lock);
		tmp = *philos;
		*philos = (*philos)->next;
		free(tmp);
	}
}

void	destroy_all(t_philo **philos, t_table *table)
{
	destroy_philos(philos);
	pthread_mutex_destroy(&table->done_eating_m);
	pthread_mutex_destroy(&table->status_m);
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

int	main(int ac, char **av)
{
	t_table		table;
	t_philo		*philos;
	pthread_t	super;

	memset(&table, 0, sizeof(table));
	philos = NULL;
	if (init_prog(ac, av, &philos, &table) == 1)
		return (1);
	if (pthread_create(&super, 0, &check_philo, philos))
	{
		destroy_all(&philos, &table);
		return (1);
	}
    if (create_philos(philos) == 1)
	{
		destroy_all(&philos, &table);
        return (1);
	}
	if (pthread_join(super, NULL) == -1)
	{
		destroy_all(&philos, &table);
		return (1);
	}
	destroy_all(&philos, &table);
 	return (0);
}
