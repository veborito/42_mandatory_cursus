/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:58:01 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/22 12:45:20 by bverdeci         ###   ########.fr       */
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

// ENUM
enum state 
{
	ALIVE,
	DEAD,
	SLEEPS,
	THINKS,
	EAT,
};

// STRUCTS
typedef struct s_philo
{
	int				id;
	int				status;
	pthread_t		philo;
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
	int				n_philo;
	pthread_mutex_t	status_m;
	int				status_g;
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