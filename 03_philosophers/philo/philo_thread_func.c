/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:06:45 by jiychoi           #+#    #+#             */
/*   Updated: 2021/09/04 17:43:18 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_hold_fork(t_philosopher *philosopher)
{
	int	timestamp;

	pthread_mutex_lock(&philosopher->fork_left->mutex_id);
	philosopher->fork_left->fork = FORK_1;
	timestamp = philo_timestamp(philosopher);
	if (timestamp - philosopher->time_eat_last_ms
		> philosopher->philo_setting->time_to_die)
		return (0);
	printf("%dms\t%d has taken a fork\n", timestamp, philosopher->index);
	if (philosopher->fork_left == philosopher->fork_right)
		return (0);
	pthread_mutex_lock(&philosopher->fork_right->mutex_id);
	timestamp = philo_timestamp(philosopher);
	if (timestamp - philosopher->time_eat_last_ms
		> philosopher->philo_setting->time_to_die)
		return (0);
	printf("%dms\t%d has taken a fork\n", timestamp, philosopher->index);
	return (1);
}

static int	philo_eat(t_philosopher *philosopher)
{
	int	time_start_eat_ms;

	time_start_eat_ms = philo_timestamp(philosopher);
	if (time_start_eat_ms < -1)
		return (0);
	printf("%dms\t%d is eating\n", time_start_eat_ms, philosopher->index);
	if (!philo_pause(philosopher, time_start_eat_ms,
			philosopher->philo_setting->time_to_eat))
		return (0);
	philosopher->time_eat_last_ms = philo_timestamp(philosopher);
	pthread_mutex_unlock(&philosopher->fork_left->mutex_id);
	philosopher->fork_left->fork = FORK_0;
	pthread_mutex_unlock(&philosopher->fork_right->mutex_id);
	philosopher->fork_right->fork = FORK_0;
	return (1);
}

static int	philo_sleep(t_philosopher *philosopher)
{
	int	time_start_sleep_ms;

	time_start_sleep_ms = philo_timestamp(philosopher);
	if (time_start_sleep_ms < 0)
		return (0);
	printf("%dms\t%d is sleeping\n", time_start_sleep_ms, philosopher->index);
	return (philo_pause(philosopher, time_start_sleep_ms,
			philosopher->philo_setting->time_to_sleep));
}

void	*philo_thread_func(void *data)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)data;
	while (philosopher->philo_setting->if_dead == NO_ONE_DEAD)
	{
		if (!philo_hold_fork(philosopher))
			return (philo_death_print(philosopher));
		if (!philo_eat(philosopher))
			return (philo_death_print(philosopher));
		if (philosopher->philo_setting->num_to_eat > 0)
		{
			philosopher->num_ate++;
			if (philosopher->num_ate == philosopher->philo_setting->num_to_eat)
				philosopher->philo_setting->num_of_philo_ate++;
		}
		if (!philo_sleep(philosopher))
			return (philo_death_print(philosopher));
		printf("%dms\t%d is thinking\n",
			philo_timestamp(philosopher), philosopher->index);
	}
	return (0);
}
