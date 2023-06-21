/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:47:54 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/21 17:21:26 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo			*philo;
	pthread_mutex_t	eat_m;
	int				eat;
	long int		t1;

	philo = (t_philo *)arg;
	t1 = get_time();
	eat = 0;
	if (philo->table->n_philo == 1)
	{
		pthread_mutex_lock(&philo->fork);
		printf("%ld ms -- %d has taken a fork\n", get_time() - t1, philo->id);
		while (get_time() - t1 < philo->table->t_die)
			continue ;
		printf("%ld ms -- %d died\n", get_time() - t1, philo->id);
		return (NULL);
	}
	if (pthread_mutex_init(&eat_m, NULL) != 0)
		return (NULL);
	while (eat < philo->table->foods)
	{
		if (philo->id % 2 == 0)
			usleep(500);
		pthread_mutex_lock(&philo->fork);
		printf("%ld ms -- %d has taken a fork\n", get_time() - t1, philo->id);
		pthread_mutex_lock(philo->next_fork);
		printf("%ld ms -- %d has taken a fork\n", get_time() - t1, philo->id);
		printf("%ld ms -- %d is eating\n", get_time() - t1, philo->id);
		pthread_mutex_lock(&eat_m);
		eat++;
		ms_sleep(philo->table->t_eat);
		philo->lstmeal = get_time() - t1;
		pthread_mutex_unlock(&eat_m);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->next_fork);
		printf("%ld ms -- %d is sleeping\n", get_time() - t1, philo->id);
		ms_sleep(philo->table->t_sleep);
		printf("%ld ms -- %d is thinking\n", get_time() - t1, philo->id);
	}
	pthread_mutex_destroy(&eat_m);
	return (NULL);
}
