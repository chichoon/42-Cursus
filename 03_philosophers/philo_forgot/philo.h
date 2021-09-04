/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:23:02 by jiychoi           #+#    #+#             */
/*   Updated: 2021/08/06 13:36:45 by jiychoi          ###   ########.fr       */
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

typedef struct s_fork
{
	int				index;
	pthread_mutex_t	*mutex_id;
}			t_fork;

typedef struct s_philosopher
{
	t_philo_setting	*philo_setting;
	int				index;
	int				num_ate;
	t_fork			*fork_left;
	t_fork			*fork_right;
	int				time_eat_last_ms;
	int				time_sleep_start_ms;
}			t_philosopher;

typedef struct s_philo_setting
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_eat;
	int				if_dead;
	time_t			time_start_s;
	suseconds_t		time_start_us;
}				t_philo_setting;

typedef struct s_philo_struct
{
	t_philosopher	*philosophers;
	t_fork			*forks;
}				t_philo_struct;

/*
	** Philosophers: Main function
*/
t_philo_struct	*philo_init_struct(int argc, char *argv);

/*
	** Philosophers: Utilities
*/
int				ft_atoi(const char *str);
int				philo_death_print(t_philosopher *philosopher);
int				philo_free_struct(t_philo_struct *philo_struct);
int				philo_timestamp(t_philosopher *philosopher);

#endif
