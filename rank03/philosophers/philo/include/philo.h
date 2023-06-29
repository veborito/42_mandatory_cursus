/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:58:01 by bverdeci          #+#    #+#             */
/*   Updated: 2023/06/29 14:18:55 by bverdeci         ###   ########.fr       */
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

// MESSAGES
# define EAT "is eating"
# define THINKS "is thinking"
# define SLEEPS "is sleeping"
# define FORK "has taken a fork"
# define DIED "died"

// CONSTANTS
# define INT_MAX 2147483647

// ENUM
enum state 
{
	ALIVE,
	DEAD,
	SLEEPING,
	THINKING,
	EATING,
	FINISHED,
};

// STRUCTS
typedef struct s_philo
{
	int				id;
	int				status;
	pthread_mutex_t	lock;
	pthread_mutex_t	eat_m;
	pthread_mutex_t	print_m;
	int				meals;
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
	long int		t1;
	long int		t_die;
	long int		t_sleep;
	int				foods;
	int				n_philo;
	pthread_mutex_t	done_eating_m;
	int				done_eating;
	pthread_mutex_t	status_m;
	int				status;
}					t_table;

// init
int			init_table(t_table *table, t_philo **philos, char **av);
int			check_args(char **av);
int			init_prog(int ac, char **av, t_philo **philos, t_table *table);

// destroy
void		destroy_all(t_philo **philos, t_table *table);

// utils
int			my_strlen(char *s);
void		write_error(char *s);
long int	get_time(void);
void		ms_sleep(long int time);

// numbers
int			my_isdigit(int c);
int			my_atoi(char *str);

// philos
int			add_philo(t_philo **philos, t_table *table, int i);
int			create_philos(t_philo *philos);

// routine
void		*routine(void *arg);
void		*check_philo(void *arg);

// actions
void		take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);
void		print_msg(t_philo *philo, char *msg);
void		eat(t_philo *philo);
void		sleeps(t_philo *philo);
void		thinks(t_philo *philo);

#endif