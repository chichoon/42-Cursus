/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:33:04 by jiychoi           #+#    #+#             */
/*   Updated: 2021/08/03 11:13:49 by jiychoi          ###   ########.fr       */
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

static t_philosopher	*philo_set_philo(t_philo_setting *philo_setting)
{
	t_philosopher	*philosopher;
	int				index;

	index = 0;
	philosopher = (t_philosopher *)malloc(
			sizeof(t_philosopher) * philo_setting->num_of_philo);
	if (!philosopher)
		return (0);
	while (index < philo_setting->num_of_philo)
	{
		philosopher[index].index = index + 1;
		philosopher[index].num_ate = 0;
		philosopher[index].time_eat_last = 0;
		philosopher[index].time_think_start = 0;
		philosopher[index].time_sleep_start = 0;
	}
	return (philosopher);
}
