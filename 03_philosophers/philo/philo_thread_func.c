/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:06:45 by jiychoi           #+#    #+#             */
/*   Updated: 2021/09/05 16:21:15 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_eat(t_philo *philo)
{

}

static int	philo_sleep(t_philo *philo)
{
	int	start_sleep_ms;

	start_sleep_ms = philo_timestamp(philo);
	if (philo->philo_setting->if_dead == ANYONE_DEAD)
		return (0);
	printf("%dms\t%d is sleeping\n", start_sleep_ms, philo->index + 1);
	if (philo->philo_setting->if_dead == ANYONE_DEAD)
		return (0);
	return (philo_pause(philo, start_sleep_ms,
			philo->philo_setting->time_to_sleep));
}

void	*philo_thread_func(void *data)
{
	t_philo	*philo;
	int				condition;

	philo = (t_philo *)data;
	while (philo->philo_setting->if_dead == NO_ONE_DEAD)
	{
		if (!philo_hold_fork(philo) || !philo_eat(philo) || !philo_sleep(philo))
			break ;
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
