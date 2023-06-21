/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:58:01 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/21 16:07:26 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// CONSTANTS
# define INT_MAX 2147483647
# define ALIVE 10
# define DEAD 11
# define SLEEPS 12
# define THINKS 13
# define EAT 14

// STRUCTS
typedef struct s_philo
{
	int				id;
	int				status;
	pthread_t		philo;
	pthread_mutex_t	lstmeal_m;
	long int		lstmeal;
	pthread_mutex_t	fork;
	pthread_mutex_t	*next_fork;
	struct s_table	*table;
	struct s_philo	*next;
}				t_philo;

typedef struct s_table
{
	t_philo			*philos;
	long int		t_eat;
	long int		t_die;
	long int		t_sleep;
	int				foods;
}					t_table;

// init
int			init_table(t_table *table, t_philo **philos, char **av);
int			check_args(char **av);

// utils
int			my_strlen(char *s);
void		write_error(char *s);
long int	get_time(void);
void		ms_sleep(long int time);

// numbers
int			my_isdigit(int c);
int			my_atoi(char *str);

// list
int			add_philo(t_philo **philos, t_table *table, int i);

// routine
void		*routine(void *arg);
#endif