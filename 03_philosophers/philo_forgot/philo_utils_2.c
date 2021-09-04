/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:08:46 by jiychoi           #+#    #+#             */
/*   Updated: 2021/09/04 14:02:56 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_death_print(t_philosopher *philosopher)
{
	int				timestamp;
	pthread_mutex_t	*mutex;

	if (!pthread_mutex_init(mutex, NULL))
		return (-1);
	pthread_mutex_lock(mutex);
	timestamp = philo_timestamp(philosopher);
	pthread_mutex_unlock(mutex);
	printf("%dms\t%d died\n", timestamp, philosopher->index);
	philosopher->philo_setting->if_dead = ANYONE_DEAD;
	pthread_mutex_destroy(mutex);
	return (0);
}

int	philo_destroy_fork(t_fork *fork, int end_index)
{
	int	index;

	index = 0;
	while (index < end_index)
		pthread_mutex_destroy(fork[index++].mutex_id);
	free(fork);
	return (0);
}
