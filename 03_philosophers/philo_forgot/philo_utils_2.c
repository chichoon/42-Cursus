/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:08:46 by jiychoi           #+#    #+#             */
/*   Updated: 2021/08/06 15:09:16 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_death_print(t_philosopher *philosopher)
{
	int				timestamp;
	pthread_mutex_t	*mutex;

	timestamp = philo_timestamp(philosopher);
	printf("%dms\t%d died\n", timestamp, philosopher->index);
	philosopher->philo_setting->if_dead = 1;
	return (0);
}

