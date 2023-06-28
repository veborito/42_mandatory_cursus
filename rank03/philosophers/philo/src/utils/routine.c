/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:47:54 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/22 12:47:42 by bverdeci         ###   ########.fr       */
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
	if (philo->id % 2 == 0)
		usleep(500);
	while (eat < philo->table->foods)
	{
		pthread_mutex_lock(&philo->fork);
		printf("%ld ms -- %d has taken a fork\n", get_time() - t1, philo->id);
		pthread_mutex_lock(philo->next_fork);
		printf("%ld ms -- %d has taken a fork\n", get_time() - t1, philo->id);
		philo->status = EAT;
		printf("%ld ms -- %d is eating\n", get_time() - t1, philo->id);
		pthread_mutex_lock(&eat_m);
		eat++;
		ms_sleep(philo->table->t_eat);
		philo->lstmeal = get_time() - t1;
		pthread_mutex_unlock(&eat_m);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->next_fork);
		printf("%ld ms -- %d is sleeping\n", get_time() - t1, philo->id);
		philo->status = SLEEPS;
		ms_sleep(philo->table->t_sleep);
		printf("%ld ms -- %d is thinking\n", get_time() - t1, philo->id);
		philo->status = THINKS;
	}
	pthread_mutex_destroy(&eat_m);
	return (NULL);
}
