/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:06:45 by jiychoi           #+#    #+#             */
/*   Updated: 2021/08/06 13:51:55 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_hold_fork(t_philosopher *philosopher)
{
	int				timestamp;
	int				time_passed_ms;

	pthread_mutex_lock(philosopher->fork_left);
	timestamp = philo_timestamp(philosopher);
	time_passed_ms = timestamp - philosopher->time_eat_last_ms;
	if (time_passed_ms > philosopher->philo_setting->time_to_die)
		return (0);
	printf("%dms\t%d has taken a fork\n", timestamp, philosopher->index);
	pthread_mutex_lock(philosopher->fork_right);
	timestamp = philo_timestamp(philosopher);
	time_passed_ms = timestamp - philosopher->time_eat_last_ms;
	if (time_passed_ms > philosopher->philo_setting->time_to_die)
		return (0);
	printf("%dms\t%d has taken a fork\n", timestamp, philosopher->index);
	return (1);
}

static int	philo_eat(t_philosopher *philosopher)
{
	int	timestamp;
	int	time_passed_ms;

	timestamp = philo_timestamp(philosopher);
	time_passed_ms = timestamp - philosopher->time_eat_last_ms;
	if (time_passed_ms > philosopher->philo_setting->time_to_die)
		return (0);
	printf("%dms\t%d is eating\n", timestamp, philosopher->index);
	while (philo_timestamp(philosopher) - timestamp
		< philosopher->philo_setting->time_to_eat)
	{
		time_passed_ms = philo_timestamp(philosopher)
			- philosopher->time_eat_last_ms;
		if (time_passed_ms > philosopher->philo_setting->time_to_die)
			return (0);
	}
	philosopher->time_eat_last_ms = philo_timestamp(philosopher);
	pthread_mutex_unlock(philosopher->fork_left);
	pthread_mutex_unlock(philosopher->fork_right);
	return (1);
}

static int	philo_sleep(t_philosopher *philosopher)
{
	int	time_passed_eating_ms;
	int	time_passed_sleeping_ms;

	philosopher->time_sleep_start_ms = philo_timestamp(philosopher);
	while (philo_timestamp(philosopher) - philosopher->time_sleep_start_ms
		< philosopher->philo_setting->time_to_sleep)
	{
		time_passed_eating_ms = philo_timestamp(philosopher)
			- philosopher->time_eat_last_ms;
		if (time_passed_eating_ms > philosopher->philo_setting->time_to_die)
			return (0);
	}
	return (1);
}

void	*philo_thread_func(void *data)
{
	int				index;
	int				timestamp;
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)data;
	while (1)
	{
		if (!philo_hold_fork(philosopher))
			return (philo_death_print(philosopher));
		if (!philo_eat(philosopher))
			return (philo_death_print(philosopher));
		if (philosopher->philo_setting->num_of_eat > 0)
			philosopher->num_ate++;
		if (!philo_sleep(philosopher))
			return (philo_death_print(philosopher));
	}
	return (0);
}
