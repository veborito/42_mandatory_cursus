/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:34:46 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/21 16:07:38 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	my_strlen(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		continue ;
	return (i);
}

void	write_error(char *s)
{
	int	len;

	if (!s)
		return ;
	len = my_strlen(s);
	if (write(2, s, len) == -1 || write(2, "\n", 1) == -1)
		return ;
}

long int	get_time(void)
{
	struct timeval	curr_time;
	long int		time_in_ms;

	gettimeofday(&curr_time, NULL);
	time_in_ms = (curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000);
	return (time_in_ms);
}


void	ms_sleep(long int time)
{
	long int	acc_time;

	acc_time = get_time();
	while (get_time() - acc_time < time)
		usleep(time / 10);
}
