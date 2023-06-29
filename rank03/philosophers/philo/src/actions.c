/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:51:20 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/29 14:39:28 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_msg(philo, FORK);
	pthread_mutex_lock(philo->next_fork);
	print_msg(philo, FORK);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->next_fork);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	print_msg(philo, EAT);
	pthread_mutex_lock(&philo->eat_m);
	philo->status = EATING;
	philo->meals++;
	pthread_mutex_unlock(&philo->eat_m);
	ms_sleep(philo->table->t_eat);
	pthread_mutex_lock(&philo->eat_m);
	if (philo->meals == philo->table->foods)
	{
		pthread_mutex_lock(&philo->table->done_eating_m);
		philo->table->done_eating++;
		pthread_mutex_unlock(&philo->table->done_eating_m);
	}
	pthread_mutex_unlock(&philo->eat_m);
	pthread_mutex_lock(&philo->eat_m);
	philo->lstmeal = get_time() - philo->table->t1;
	pthread_mutex_unlock(&philo->eat_m);
	drop_forks(philo);
}

void	sleeps(t_philo *philo)
{
	print_msg(philo, SLEEPS);
	philo->status = SLEEPING;
	ms_sleep(philo->table->t_sleep);
}

void	thinks(t_philo *philo)
{
	print_msg(philo, THINKS);
	philo->status = THINKING;
}