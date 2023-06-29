/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:10:49 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/29 14:16:43 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*create_philo(int i, t_table *table)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (new)
	{
		new->id = i + 1;
		new->meals = 0;
		new->status = ALIVE;
		new->table = table;
		new->next = NULL;
		new->next_fork = NULL;
		if (pthread_mutex_init(&new->fork, NULL) != 0)
			return (NULL);
		if (pthread_mutex_init(&new->eat_m, NULL) != 0)
			return (NULL);
		if (pthread_mutex_init(&new->lock, NULL) != 0)
			return (NULL);
		if (pthread_mutex_init(&new->print_m, NULL) != 0)
			return (NULL);
	}
	return (new);
}

int	add_philo(t_philo **philos, t_table *table, int i)
{
	t_philo	*new;
	t_philo	*last;

	last = *philos;
	new = create_philo(i, table);
	if (!new)
		return (1);
	if (*philos == NULL)
		*philos = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return (0);
}

int	create_philos(t_philo *philos)
{
	t_philo	*temp;

	temp = philos;
	while (temp)
	{
		if (pthread_create(&philos->philo, 0, &routine, temp) == -1)
			return (1);
		temp = temp->next;
		ms_sleep(1);
	}
	temp = philos;
	while (temp)
	{
		if (pthread_join(philos->philo, NULL) == -1)
			return (1);
		temp = temp->next;
	}
	return (0);
}
