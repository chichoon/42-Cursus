/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:23:02 by jiychoi           #+#    #+#             */
/*   Updated: 2021/09/05 16:35:55 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

# define FORK_HELD	1
# define FORK_UNHELD	0
# define NO_ONE_DEAD 0
# define ANYONE_DEAD 1
# define EVERYONE_ATE 2

typedef struct s_philo_setting
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_to_eat;
	int				num_of_philo;
	int				num_of_philo_ate;
	int				if_dead;
	time_t			time_start_s;
	suseconds_t		time_start_us;
	pthread_mutex_t	death_mutex;
}				t_philo_setting;

typedef struct s_fork
{
	int				index;
	int				fork;
	pthread_mutex_t	mutex_id;
}			t_fork;

typedef struct s_philo
{
	t_philo_setting	*philo_setting;
	int				index;
	int				num_ate;
	pthread_t		thread_id;
	t_fork			*fork_left;
	t_fork			*fork_right;
	int				time_eat_last_ms;
}			t_philo;

typedef struct s_philo_struct
{
	t_philo_setting	*philo_setting;
	t_philo			*philos;
	t_fork			*forks;
}				t_philo_struct;

/*
	** Philosophers: Main function
*/
t_philo_struct	*philo_init_struct(int argc, char *argv[]);
void			*philo_thread_func(void *data);

/*
	** Philosophers: Utilities
*/
int				ft_atoi(const char *str);
void			*philo_death_print(t_philo *philo, int if_dead);
int				philo_timestamp(t_philo *philo);
int				philo_set_num_eat(t_philo *philo);
int				philo_pause(
					t_philo *philo,
					int time_start,
					int time_threshold);
t_fork			*philo_destroy_fork(t_fork *fork, int end_index);
t_philo_struct	*philo_free_struct(
					t_philo_setting *philo_setting,
					t_philo *philo,
					t_fork *forks,
					t_philo_struct *philo_struct);

#endif
