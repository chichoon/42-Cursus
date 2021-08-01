/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:37:13 by jiychoi           #+#    #+#             */
/*   Updated: 2021/08/01 12:33:55 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosophers(t_philo_setting *philo_setting)
{
	int				index;
	struct timeval	*tp;

	index = 0;
	while (index < philo_setting->num_of_philo)
	{
		gettimeofday(tp, NULL);
		printf("%dus	Philosopher %d died\n", tp->tv_usec);
	}
}

void	philo_init_struct(t_philo_setting *philo_setting,
	int argc, char *argv[])
{
	philo_setting->num_of_philo = ft_atoi(argv[1]);
	philo_setting->time_to_die = ft_atoi(argv[2]);
	philo_setting->time_to_eat = ft_atoi(argv[3]);
	philo_setting->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo_setting->num_of_eat = ft_atoi(argv[5]);
	else
		philo_setting->num_of_eat = -1;
}

int	main(int argc, char *argv[])
{
	t_philo_setting	*philo_setting;

	if (argc != 5 && argc != 6)
		printf("Too few arguments to call. Stop.\n");
	else
	{
		philo_setting = (t_philo_setting *)malloc(sizeof(t_philo_setting));
		philo_init_struct(philo_setting, argc, argv);
		philosophers(philo_setting);
		free(philo_setting);
	}
}
