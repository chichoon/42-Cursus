/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:02:18 by jiychoi           #+#    #+#             */
/*   Updated: 2021/08/06 15:08:55 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_space(char str)
{
	if (str == ' ' || (str >= 9 && str <= 13))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long long	absol;
	int					minus;

	minus = 1;
	absol = 0;
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
		absol = absol * 10 + (*str++ - '0');
	if (absol >= 9223372036854775807 && minus == 1)
		return (-1);
	else if (absol >= 9223372036854775807 && minus == -1)
		return (0);
	return (minus * absol);
}

int	philo_free_struct(t_philo_struct *philo_struct)
{
	free(philo_struct->philosophers[0].philo_setting);
	free(philo_struct->philosophers);
	free(philo_struct->forks);
	return (0);
}

int	philo_timestamp(t_philosopher *philosopher)
{
	struct timeval	tp;
	int				timestamp;

	if (!gettimeofday(&tp, NULL))
		return (0);
	timestamp
		= (tp.tv_sec - philosopher->philo_setting->time_start_s) * 1000
		+ (tp.tv_usec - philosopher->philo_setting->time_start_us) / 1000;
	return (timestamp);
}
