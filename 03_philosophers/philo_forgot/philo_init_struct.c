/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:33:04 by jiychoi           #+#    #+#             */
/*   Updated: 2021/09/04 14:21:53 by jiychoi          ###   ########.fr       */
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
	philo_setting->num_of_philo_ate = 0;
	philo_setting->if_dead = NO_ONE_DEAD;
	if (argc == 6)
		philo_setting->num_to_eat = ft_atoi(argv[5]);
	else
		philo_setting->num_to_eat = -1;
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
		philosophers[index].philo_setting = philo_setting;
		philosophers[index].index = index;
		philosophers[index].num_ate = 0;
		philosophers[index].time_eat_last_ms = 0;
		philosophers[index].time_sleep_start_ms = 0;
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
	if (!forks)
		return (0);
	while (index < philo_setting->num_of_philo)
	{
		if (!pthread_mutex_init(temp_mutex, NULL))
		{
			forks[index].index = index;
			forks[index].fork = FORK_0;
			forks[index].mutex_id = temp_mutex;
			index++;
		}
		else
			return (philo_destroy_fork(forks, index));
	}
	return (forks);
}

static void	philo_put_forks(t_philo_struct *philo_struct)
{
	t_philosopher	*philosophers;
	t_fork			*forks;
	t_philo_setting	*philo_setting;
	int				index;
	int				max_index;

	philosophers = philo_struct->philosophers;
	forks = philo_struct->forks;
	philo_setting = philosophers[0].philo_setting;
	index = -1;
	max_index = philo_setting->num_of_philo;
	while (++index < philo_setting->num_of_philo)
	{
		philosophers[index].fork_left = &forks[index];
		if (index == max_index - 1)
			philosophers[index].fork_right = &forks[0];
		else
			philosophers[index].fork_right = &forks[index + 1];
	}
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
	philo_struct->philosophers = philosophers;
	philo_struct->forks = forks;
	return (philo_struct);
}
