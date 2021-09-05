/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:06:45 by jiychoi           #+#    #+#             */
/*   Updated: 2021/09/05 16:57:59 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_hold_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_left->mutex_id);
	philo->fork_left->fork = FORK_HELD;
	if ((philo_timestamp(philo) - philo->time_eat_last_ms
			> philo->philo_setting->time_to_die)
		|| philo->philo_setting->if_dead != NO_ONE_DEAD)
		return (0);
	else
		printf("%dms\t%d has taken a fork\n",
			philo_timestamp(philo), philo->index + 1);
	if (philo->fork_left == philo->fork_right)
		return (0);
	pthread_mutex_lock(&philo->fork_right->mutex_id);
	philo->fork_right->fork = FORK_HELD;
	if ((philo_timestamp(philo) - philo->time_eat_last_ms
			> philo->philo_setting->time_to_die)
		|| philo->philo_setting->if_dead != NO_ONE_DEAD)
		return (0);
	else
		printf("%dms\t%d has taken a fork\n",
			philo_timestamp(philo), philo->index + 1);
	return (1);
}

static int	philo_eat(t_philo *philo)
{
	if (philo->philo_setting->if_dead != NO_ONE_DEAD)
		return (0);
	else
		printf("%dms\t%d is eating\n",
			philo_timestamp(philo), philo->index + 1);
	if (philo->philo_setting->if_dead != NO_ONE_DEAD)
		return (0);
	if (!philo_pause(philo, philo_timestamp(philo),
			philo->philo_setting->time_to_eat))
		return (0);
	philo->time_eat_last_ms = philo_timestamp(philo);
	pthread_mutex_unlock(&philo->fork_left->mutex_id);
	philo->fork_left->fork = FORK_UNHELD;
	pthread_mutex_unlock(&philo->fork_right->mutex_id);
	philo->fork_right->fork = FORK_UNHELD;
	if (philo->philo_setting->if_dead != NO_ONE_DEAD)
		return (0);
	return (philo_set_num_eat(philo));
}

static int	philo_sleep(t_philo *philo)
{
	if (philo->philo_setting->if_dead != NO_ONE_DEAD)
		return (0);
	else
		printf("%dms\t%d is sleeping\n",
			philo_timestamp(philo), philo->index + 1);
	if (philo->philo_setting->if_dead != NO_ONE_DEAD)
		return (0);
	return (philo_pause(philo, philo_timestamp(philo),
			philo->philo_setting->time_to_sleep));
}

void	*philo_thread_func(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo->philo_setting->if_dead == NO_ONE_DEAD)
	{
		if (!philo_hold_fork(philo) || !philo_eat(philo) || !philo_sleep(philo))
			break ;
		if (philo->philo_setting->if_dead != NO_ONE_DEAD)
			break ;
		else
			printf("%dms\t%d is thinking\n", philo_timestamp(philo),
				philo->index + 1);
	}
	if (philo->philo_setting->if_dead == NO_ONE_DEAD)
	{
		if (philo->philo_setting->num_of_philo_ate
			== philo->philo_setting->num_to_eat)
			return (philo_death_print(philo, EVERYONE_ATE));
		else
			return (philo_death_print(philo, ANYONE_DEAD));
	}
	return (0);
}
