/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:53:46 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/30 09:33:10 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_dead(t_philo *temp)
{
	long int	time;

	pthread_mutex_lock(&temp->lock);
	pthread_mutex_lock(&temp->eat_m);
	time = (get_time() - temp->table->t1) - temp->lstmeal;
	pthread_mutex_unlock(&temp->eat_m);
	if (time >= temp->table->t_die)
	{
		print_msg(temp, DIED);
		pthread_mutex_lock(&temp->table->status_m);
		temp->table->status = FINISHED;
		pthread_mutex_unlock(&temp->table->status_m);
		return (1);
	}
	pthread_mutex_unlock(&temp->lock);
	return (0);
}

static int	all_done_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->done_eating_m);
	if (philo->table->done_eating == philo->table->n_philo)
	{
		pthread_mutex_unlock(&philo->table->done_eating_m);
		pthread_mutex_lock(&philo->table->status_m);
		philo->table->status = FINISHED;
		pthread_mutex_unlock(&philo->table->status_m);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->done_eating_m);
	return (0);
}

void	*check_philo(void *arg)
{
	t_philo		*philo;
	t_philo		*temp;

	philo = (void *)arg;
	if (philo->table->n_philo == 1)
		return (NULL);
	while (philo->table->status != FINISHED)
	{
		temp = philo;
		while (temp)
		{
			if (is_dead(temp))
				break ;
			if (all_done_eating(philo))
				break ;
			temp = temp->next;
		}
	}
	return (NULL);
}
