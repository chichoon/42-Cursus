/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:23:02 by jiychoi           #+#    #+#             */
/*   Updated: 2021/08/03 10:26:35 by jiychoi          ###   ########.fr       */
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
	pthread_mutex_t	*mutex_id;
}			t_fork;

typedef struct s_philosopher
{
	int			index;
	int			num_ate;
	t_fork		*fork_left;
	t_fork		*fork_right;
	suseconds_t	time_eat_last;
	suseconds_t	time_think_start;
	suseconds_t	time_sleep_start;
}			t_philosopher;

typedef struct s_philo_setting
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_eat;
}				t_philo_setting;

typedef struct s_philo_struct
{
	t_philosopher	*philosopher;
	t_philo_setting	philo_setting;
}				t_philo_struct;

/*
	** Philosophers: Main function
*/
int		philo_init(t_philo_set philo_set, int argc, char *argv[]);

/*
	** Philosophers: Utilities
*/
int		ft_atoi(const char *str);
int		philo_print_and_return(char *str);

#endif
