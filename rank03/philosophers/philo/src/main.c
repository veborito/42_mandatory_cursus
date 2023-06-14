/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:57:34 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/14 15:09:04 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	*get_tab(void)
{
	int	*numbers;
	int	i;

	i = -1;
	numbers = malloc(sizeof(int) * 10);
	while (i++ < 10)
		numbers[i] = i + 1;
	return (numbers);
}

void	*routine(void *arg)
{
	int	index;
	int	*tab;
	int	sum;
	int	i;

	tab = get_tab();
	index = *(int *)arg;
	sum = 0;
	i = -1;
	while (i++ < 5)
		sum += tab[index];
	free(tab);
	*(int *)arg = sum;
	return (arg);
}

int	main(void)
{
	pthread_t	th[2];
	int			i;
	int			*a;
	int			*r;
	int			global_sum;

	i = -1;
	while (++i < 2)
	{
		a = malloc(sizeof(int));
		*a = i * 5;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
			return (1);
	}
	i = -1;
	global_sum = 0;
	while (++i < 2)
	{
		if (pthread_join(th[i], (void **)&r) != 0)
			return (1);
		global_sum += *r;
		free(r);
	}
	printf("Global Sum: %d\n", global_sum);
	return (0);
}
