/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:08:46 by jiychoi           #+#    #+#             */
/*   Updated: 2021/09/11 11:02:52 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_death_print(t_philo *philo, int if_dead)
{
	int				timestamp;

	timestamp = philo_timestamp(philo);
	if (if_dead == EVERYONE_ATE)
		philo->philo_setting->if_dead = EVERYONE_ATE;
	else if (philo->philo_setting->if_dead == NO_ONE_DEAD)
	{
		philo->philo_setting->if_dead = ANYONE_DEAD;
		printf("%d\t%d died\n", timestamp, philo->index + 1);
	}
	pthread_mutex_unlock(&philo->philo_setting->death_mutex);
	return (0);
}

int	philo_pause(t_philo *philo, int time_start, int time_threshold)
{
	while (philo_timestamp(philo) - time_start < time_threshold)
	{
		if (philo->philo_setting->if_dead != NO_ONE_DEAD
			|| (philo_timestamp(philo) - philo->time_eat_last_ms
				> philo->philo_setting->time_to_die))
			return (0);
	}
	return (1);
}

t_fork	*philo_destroy_fork(t_fork *fork, int end_index)
{
	int	index;

	index = 0;
	while (index < end_index)
		pthread_mutex_destroy(&fork[index++].mutex_id);
	free(fork);
	return (0);
}

t_philo_struct	*philo_free_struct(
	t_philo_setting *philo_setting,
	t_philo *philo,
	t_fork *forks,
	t_philo_struct *philo_struct)
{
	pthread_mutex_t	death_mutex_tmp;
	int				if_philo_death;

	if_philo_death = 0;
	if (philo_struct)
	{
		death_mutex_tmp = philo_setting->death_mutex;
		pthread_mutex_lock(&death_mutex_tmp);
		if_philo_death = 1;
	}
	if (philo)
		free(philo);
	if (forks)
		philo_destroy_fork(forks, philo_setting->num_of_philo);
	if (philo_setting)
		free(philo_setting);
	if (philo_struct)
		free(philo_struct);
	if (if_philo_death)
	{
		pthread_mutex_unlock(&death_mutex_tmp);
		pthread_mutex_destroy(&death_mutex_tmp);
	}
	return (0);
}
