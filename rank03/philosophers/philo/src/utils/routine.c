/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:47:54 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/29 09:33:39 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *philo, char *msg)
{
	if (philo->table->status == FINISHED)
		return ;
	pthread_mutex_lock(&philo->print_m);
	printf("%ld %d %s\n", get_time() - philo->table->t1, philo->id, msg);
	pthread_mutex_unlock(&philo->print_m);
}

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
	if (philo->table->status == FINISHED)
		return ;
	take_forks(philo);
	print_msg(philo, EAT);
	pthread_mutex_lock(&philo->eat_m);
	philo->status = EATING;
	philo->meals++;
	pthread_mutex_unlock(&philo->eat_m);
	ms_sleep(philo->table->t_eat);
	philo->lstmeal = get_time() - philo->table->t1;
	drop_forks(philo);
}

void	sleeps(t_philo *philo)
{
	if (philo->table->status == FINISHED)
		return ;
	print_msg(philo, SLEEPS);
	philo->status = SLEEPING;
	ms_sleep(philo->table->t_sleep);
}

void	thinks(t_philo *philo)
{
	if (philo->table->status == FINISHED)
		return ;
	print_msg(philo, THINKS);
	philo->status = THINKING;
}

void	*check_philo(void *arg)
{
	t_philo		*philo;
	t_philo		*temp;
	long int	time;

	philo = (void *)arg;
	while (philo->table->status != FINISHED)
	{
		temp = philo;
		while (temp)
		{
			time = (get_time() - temp->table->t1) - temp->lstmeal;
			if (time >= temp->table->t_die)
			{
				print_msg(temp, DIED);
				pthread_mutex_lock(&temp->table->status_m);
				temp->table->status = FINISHED;
				pthread_mutex_unlock(&temp->table->status_m);
				break;
			}
			temp = temp->next;
		}
	}
	return (NULL);
}

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
	if (philo->id % 2 == 0)
		usleep(500);
	while (philo->table->status != FINISHED)
	{
		if (philo->table->status != FINISHED)
		{
			eat(philo);
			sleeps(philo);
			thinks(philo);
		}
	}
	return (NULL);
}
