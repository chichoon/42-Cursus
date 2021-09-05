/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:06:45 by jiychoi           #+#    #+#             */
/*   Updated: 2021/09/05 16:20:42 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_hold_fork(t_philo *philo)
{
	int	timestamp;

	pthread_mutex_lock(&philo->fork_left->mutex_id);
	philo->fork_left->fork = FORK_1;
	timestamp = philo_timestamp(philo);
	if (timestamp - philo->time_eat_last_ms
		> philo->philo_setting->time_to_die)
		return (0);
	if (philo->philo_setting->if_dead == NO_ONE_DEAD)
		printf("%dms\t%d has taken a fork\n", timestamp, philo->index + 1);
	if (philo->fork_left == philo->fork_right)
		return (0);
	pthread_mutex_lock(&philo->fork_right->mutex_id);
	philo->fork_right->fork = FORK_1;
	timestamp = philo_timestamp(philo);
	if (timestamp - philo->time_eat_last_ms
		> philo->philo_setting->time_to_die)
		return (0);
	if (philo->philo_setting->if_dead == NO_ONE_DEAD)
		printf("%dms\t%d has taken a fork\n", timestamp, philo->index + 1);
	return (1);
}

static int	philo_eat(t_philo *philo)
{
	int	time_start_eat_ms;

	time_start_eat_ms = philo_timestamp(philo);
	if (time_start_eat_ms < -1)
		return (0);
	if (philo->philo_setting->if_dead == NO_ONE_DEAD)
		printf("%dms\t%d is eating\n", time_start_eat_ms, philo->index + 1);
	if (!philo_pause(philo, time_start_eat_ms,
			philo->philo_setting->time_to_eat))
		return (0);
	philo->time_eat_last_ms = philo_timestamp(philo);
	pthread_mutex_unlock(&philo->fork_left->mutex_id);
	philo->fork_left->fork = FORK_0;
	pthread_mutex_unlock(&philo->fork_right->mutex_id);
	philo->fork_right->fork = FORK_0;
	if (philo->philo_setting->num_to_eat > 0)
	{
		philo->num_ate++;
		if (philo->num_ate == philo->philo_setting->num_to_eat)
			philo->philo_setting->num_of_philo_ate++;
	}
	return (1);
}

static int	philo_sleep(t_philo *philo)
{
	int	time_start_sleep_ms;

	time_start_sleep_ms = philo_timestamp(philo);
	if (time_start_sleep_ms < 0)
		return (0);
	if (philo->philo_setting->if_dead == NO_ONE_DEAD)
		printf("%dms\t%d is sleeping\n", time_start_sleep_ms,
			philo->index + 1);
	return (philo_pause(philo, time_start_sleep_ms,
			philo->philo_setting->time_to_sleep));
	return (1);
}

void	*philo_thread_func(void *data)
{
	t_philo			*philo;
	t_philo_setting	*philo_setting;

	philo = (t_philo *)data;
	philo_setting = philo->philo_setting;
	while (philo_setting->if_dead == NO_ONE_DEAD)
	{
		if (!philo_hold_fork(philo) || !philo_eat(philo))
			return (philo_death_print(philo, ANYONE_DEAD));
		if (philo_setting->num_of_philo_ate == philo_setting->num_of_philo)
			return (philo_death_print(philo, EVERYONE_ATE));
		if (!philo_sleep(philo))
			return (philo_death_print(philo, ANYONE_DEAD));
		printf("%dms\t%d is thinking\n", philo_timestamp(philo),
			philo->index + 1);
	}
	return (0);
}
