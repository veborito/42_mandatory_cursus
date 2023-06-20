/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:57:34 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/20 18:33:44 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*  --- DEBUG -------

	while (temp)
	{
		printf("philo : %d -- table : %p -- fork : %p --\
next_fork : %p -- status: %d\n",
			temp->id, temp->table, &temp->fork, temp->next_fork, temp->status);
		temp = temp->next;
	}
*/

/*
----- TODO ------
- Creer la routine pour un philo
- faire une fonction pour sleep et checker si un philo meurs en meme temps qu'il fait une autre action.

*/

int	main(int ac, char **av)
{
	t_table	table;
	t_philo	*philos;

	memset(&table, 0, sizeof(table));
	philos = NULL;
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
	if (init_table(&table, &philos, av))
	{
		write_error("Initialization error");
		return (1);
	}
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
 	return (0);
}
