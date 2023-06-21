/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:47:54 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/21 16:08:39 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo			*philo;
	pthread_mutex_t	eat_m;
	int				eat;
	long int		t1;
	long int		t2;

	philo = (t_philo *)arg;
	t1 = get_time();
	eat = 0;
	if (pthread_mutex_init(&eat_m, NULL) != 0)
		return (NULL);
	while (eat < philo->table->foods)
	{
		if (philo->id % 2 == 0)
			ms_sleep(500);
		if (pthread_mutex_lock(&philo->fork) != 0)
			printf("error\n");
		t2 = get_time();
		printf("%ld ms -- %d has taken a fork\n", t2 - t1, philo->id);
		if (pthread_mutex_lock(philo->next_fork) != 0)
			printf("error\n");
		t2 = get_time();
		printf("%ld ms -- %d has taken a fork\n", t2 - t1, philo->id);
		t2 = get_time();
		printf("%ld ms -- %d is eating\n", t2 - t1, philo->id);
		pthread_mutex_lock(&eat_m);
		eat++;
		ms_sleep(philo->table->t_eat * 1000);
		pthread_mutex_unlock(&eat_m);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->next_fork);
		t2 = get_time();
		printf("%ld ms -- %d is sleeping\n", t2 - t1, philo->id);
		ms_sleep(philo->table->t_sleep * 1000);
		t2 = get_time();
		printf("%ld ms -- %d is thinking\n", t2 - t1, philo->id);
	}
	return (NULL);
}
