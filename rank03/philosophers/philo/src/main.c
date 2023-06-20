/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:57:34 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/20 17:11:42 by bverdeci         ###   ########.fr       */
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
	if (init_table(&table, &philos, av))
	{
		write_error("Initialization error");
		return (1);
	}
	return (0);
}
