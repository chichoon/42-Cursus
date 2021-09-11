/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:37:13 by jiychoi           #+#    #+#             */
/*   Updated: 2021/09/11 11:49:39 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosophers(t_philo_struct *philo_struct)
{
	struct timeval	tp;
	int				index;
	pthread_t		thread_tmp;
	int				int_tmp;

	if (gettimeofday(&tp, NULL) < 0)
		return ;
	philo_struct->philo_setting->time_start_s = tp.tv_sec;
	philo_struct->philo_setting->time_start_us = tp.tv_usec;
	while (++index < philo_struct->philo_setting->num_of_philo)
	{
		if (index % 2)
			usleep(50);
		if (pthread_create(&thread_tmp, NULL, philo_thread_func,
				&philo_struct->philos[index]) != 0)
			return ;
		philo_struct->philos[index].thread_id = thread_tmp;
	}
	index = -1;
	while (++index < philo_struct->philo_setting->num_of_philo)
		pthread_join(philo_struct->philos[index].thread_id, (void **)&int_tmp);
}

int	main(int argc, char *argv[])
{
	t_philo_struct	*philo_struct;

	if (argc != 5 && argc != 6)
	{
		printf("Argument number error. Stop.\n");
		return (0);
	}
	philo_struct = philo_init_struct(argc, argv);
	if (!philo_struct)
	{
		printf("Initialization Failed. Stop.\n");
		return (0);
	}
	philosophers(philo_struct);
	philo_free_struct(philo_struct->philo_setting, philo_struct->philos,
		philo_struct->forks, philo_struct);
	return (0);
}
