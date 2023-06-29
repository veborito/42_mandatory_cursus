/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:48:52 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/29 13:50:13 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_philos(t_philo **philos)
{
	t_philo	*tmp;

	while (*philos)
	{
		tmp = *philos;
		pthread_mutex_destroy(&tmp->eat_m);
		pthread_mutex_destroy(&tmp->fork);
		pthread_mutex_destroy(&tmp->print_m);
		pthread_mutex_destroy(&tmp->lock);
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
