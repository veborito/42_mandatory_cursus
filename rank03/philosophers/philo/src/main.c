/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:57:34 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/29 14:18:22 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
