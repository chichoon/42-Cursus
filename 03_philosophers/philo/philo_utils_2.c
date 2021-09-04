/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:08:46 by jiychoi           #+#    #+#             */
/*   Updated: 2021/09/04 17:47:14 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_death_print(t_philosopher *philosopher)
{
	int				timestamp;
	pthread_mutex_t	mutex;

	if (pthread_mutex_init(&mutex, NULL) < 0)
	{
		printf("Death mutex initialization failed. Exit...\n");
		philosopher->philo_setting->if_dead = ANYONE_DEAD;
		return (0);
	}
	pthread_mutex_lock(&mutex);
	timestamp = philo_timestamp(philosopher);
	pthread_mutex_unlock(&mutex);
	printf("%dms\t%d died\n", timestamp, philosopher->index);
	philosopher->philo_setting->if_dead = ANYONE_DEAD;
	pthread_mutex_destroy(&mutex);
	return (0);
}

int	philo_pause(t_philosopher *philosopher, int time_start, int time_threshold)
{
	int	timestamp;

	timestamp = philo_timestamp(philosopher);
	if (timestamp < 0)
		return (-1);
	while (timestamp - time_start < time_threshold)
	{
		timestamp = philo_timestamp(philosopher);
		if (timestamp < 0
			|| (timestamp - philosopher->time_eat_last_ms
				> philosopher->philo_setting->time_to_die))
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

t_philo_struct	*philo_free_struct(t_philo_setting *philo_setting,
	t_philosopher *philosophers,
	t_fork *forks,
	t_philo_struct *philo_struct)
{
	if (philosophers)
		free(philosophers);
	if (forks)
		philo_destroy_fork(forks, philo_setting->num_of_philo);
	if (philo_setting)
		free(philo_setting);
	if (philo_struct)
		free(philo_struct);
	return (0);
}
