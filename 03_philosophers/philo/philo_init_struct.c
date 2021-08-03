/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:33:04 by jiychoi           #+#    #+#             */
/*   Updated: 2021/08/03 12:54:28 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo_setting	*philo_set_setting(int argc, char *argv)
{
	t_philo_setting	*philo_setting;

	philo_setting = (t_philo_setting *)malloc(sizeof(philo_setting));
	if (!philo_setting)
		return (0);
	philo_setting->num_of_philo = ft_atoi(argv[1]);
	philo_setting->time_to_die = ft_atoi(argv[2]);
	philo_setting->time_to_eat = ft_atoi(argv[3]);
	philo_setting->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo_setting->num_of_eat = ft_atoi(argv[5]);
	else
		philo_setting->num_of_eat = -1;
	return (philo_setting);
}

static t_philosopher	*philo_set_philos(t_philo_setting *philo_setting)
{
	t_philosopher	*philosophers;
	int				index;

	index = 0;
	philosophers = (t_philosopher *)malloc(
			sizeof(t_philosopher) * philo_setting->num_of_philo);
	if (!philosophers)
		return (0);
	while (index < philo_setting->num_of_philo)
	{
		philosophers[index].index = index + 1;
		philosophers[index].num_ate = 0;
		philosophers[index].time_eat_last = 0;
		philosophers[index].time_think_start = 0;
		philosophers[index].time_sleep_start = 0;
		index++;
	}
	return (philosophers);
}

static t_fork	*philo_set_forks(t_philo_setting *philo_setting)
{
	t_fork			*forks;
	int				index;
	pthread_mutex_t	*temp_mutex;

	index = 0;
	forks = (t_fork *)malloc(
			sizeof(t_fork) * philo_setting->num_of_philo);
	while (index < philo_setting->num_of_philo)
	{
		if (!pthread_mutex_init(temp_mutex, NULL))
		{
			forks[index].index = index;
			forks[index].mutex_id = temp_mutex;
			index++;
		}
	}
	return (forks);
}

t_philo_struct	*philo_init_struct(int argc, char *argv)
{
	t_philo_struct	*philo_struct;
	t_philo_setting	*philo_setting;
	t_philosopher	*philosophers;
	t_fork			*forks;

	philo_setting = philo_set_setting(argc, argv);
	if (!philo_setting)
		return (0);
	philosophers = philo_set_philos(philo_setting);
	if (!philosophers)
		return (0);
	forks = philo_set_forks(philo_setting);
	if (!forks)
		return (0);
	philo_struct = (t_philo_struct *)malloc(sizeof(t_philo_struct));
	philo_struct->philo_setting = philo_setting;
	philo_struct->philosophers = philosophers;
	philo_struct->forks = forks;
	return (philo_struct);
}
