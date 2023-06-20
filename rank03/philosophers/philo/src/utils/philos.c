/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:10:49 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/20 15:45:02 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philo(int i, t_table *table)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (new)
	{
		new->id = i + 1;
		new->status = ALIVE;
		new->table = table;
		new->next = NULL;
		pthread_mutex_init(&new->fork, NULL);
		new->next_fork = NULL;
	}
	return (new);
}

void	add_philo(t_philo **philos, t_table *table, int i)
{
	t_philo	*new;
	t_philo	*last;

	last = *philos;
	new = create_philo(i, table);
	if (!new)
		return ;
	if (*philos == NULL)
		*philos = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}
