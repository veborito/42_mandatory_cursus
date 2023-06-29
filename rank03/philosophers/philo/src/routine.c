/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:47:54 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/29 14:24:12 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->n_philo == 1)
	{
		pthread_mutex_lock(&philo->fork);
		print_msg(philo, FORK);
		while (get_time() - philo->table->t1 < philo->table->t_die)
			continue ;
		print_msg(philo, DIED);
		pthread_mutex_unlock(&philo->fork);
		return (NULL);
	}
	while (1)
	{
		pthread_mutex_lock(&philo->table->status_m);
		if(philo->table->status != FINISHED)
		{
			pthread_mutex_unlock(&philo->table->status_m);
			eat(philo);
			sleeps(philo);
			thinks(philo);
		}
		else
		{
			pthread_mutex_unlock(&philo->table->status_m);
			break ;
		}
	}
	return (NULL);
}
