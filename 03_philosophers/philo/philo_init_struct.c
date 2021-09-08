/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:33:04 by jiychoi           #+#    #+#             */
/*   Updated: 2021/09/08 11:17:26 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo_setting	*philo_set_setting(int argc, char *argv[])
{
	t_philo_setting	*philo_setting;

	philo_setting = (t_philo_setting *)malloc(sizeof(t_philo_setting));
	if (!philo_setting)
		return (0);
	philo_setting->num_of_philo = ft_atoi(argv[1]);
	philo_setting->time_to_die = ft_atoi(argv[2]);
	philo_setting->time_to_eat = ft_atoi(argv[3]);
	philo_setting->time_to_sleep = ft_atoi(argv[4]);
	philo_setting->num_of_philo_ate = 0;
	philo_setting->if_dead = NO_ONE_DEAD;
	if (philo_setting->num_of_philo < 1 || philo_setting->time_to_die < 0
		|| philo_setting->time_to_eat < 0 || philo_setting->time_to_sleep < 0
		|| pthread_mutex_init(&philo_setting->death_mutex, NULL) < 0)
		return (0);
	if (argc == 6)
	{
		philo_setting->num_to_eat = ft_atoi(argv[5]);
		if (philo_setting->num_to_eat < 0)
			return (0);
	}
	else
		philo_setting->num_to_eat = -1;
	return (philo_setting);
}

static t_philo	*philo_set_philos(t_philo_setting *philo_setting)
{
	t_philo	*philos;
	int		index;

	index = 0;
	philos = (t_philo *)malloc(
			sizeof(t_philo) * philo_setting->num_of_philo);
	if (!philos)
		return (0);
	while (index < philo_setting->num_of_philo)
	{
		philos[index].philo_setting = philo_setting;
		philos[index].index = index;
		philos[index].num_ate = 0;
		philos[index].time_eat_last_ms = 0;
		index++;
	}
	return (philos);
}

static t_fork	*philo_set_forks(t_philo_setting *philo_setting)
{
	t_fork			*forks;
	int				index;
	pthread_mutex_t	temp_mutex;

	index = 0;
	forks = (t_fork *)malloc(
			sizeof(t_fork) * philo_setting->num_of_philo);
	if (!forks)
		return (0);
	while (index < philo_setting->num_of_philo)
	{
		if (!pthread_mutex_init(&temp_mutex, NULL))
		{
			forks[index].index = index;
			forks[index].fork = FORK_UNHELD;
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
	t_philo			*philos;
	t_fork			*forks;
	t_philo_setting	*philo_setting;
	int				index;
	int				max_index;

	philos = philo_struct->philos;
	forks = philo_struct->forks;
	philo_setting = philos[0].philo_setting;
	index = -1;
	max_index = philo_setting->num_of_philo;
	while (++index < philo_setting->num_of_philo)
	{
		philos[index].fork_left = &forks[index];
		if (index == max_index - 1)
			philos[index].fork_right = &forks[0];
		else
			philos[index].fork_right = &forks[index + 1];
	}
}

t_philo_struct	*philo_init_struct(int argc, char *argv[])
{
	t_philo_struct	*philo_struct;
	t_philo_setting	*philo_setting;
	t_philo			*philos;
	t_fork			*forks;

	philo_setting = philo_set_setting(argc, argv);
	if (!philo_setting)
		return (philo_free_struct(0, 0, 0, 0));
	philos = philo_set_philos(philo_setting);
	if (!philos)
		return (philo_free_struct(philo_setting, 0, 0, 0));
	forks = philo_set_forks(philo_setting);
	if (!forks)
		return (philo_free_struct(philo_setting, philos, 0, 0));
	philo_struct = (t_philo_struct *)malloc(sizeof(t_philo_struct));
	if (!philo_struct)
		return (philo_free_struct(philo_setting, philos, forks, 0));
	philo_struct->philo_setting = philo_setting;
	philo_struct->philos = philos;
	philo_struct->forks = forks;
	philo_put_forks(philo_struct);
	return (philo_struct);
}
