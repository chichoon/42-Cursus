/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:02:18 by jiychoi           #+#    #+#             */
/*   Updated: 2021/09/11 11:55:32 by jiychoi          ###   ########.fr       */
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

static int	is_num(const char *str)
{
	while (*str)
	{
		if ((*str > '9' || *str < '0')
			&& (*str != '+') && (*str != '-'))
			return (0);
		str++;
	}
	return (1);
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
	if (!is_num(str))
		return (-1);
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

int	philo_timestamp(t_philo *philo)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec - philo->philo_setting->time_start_s) * 1000
		+ (tp.tv_usec - philo->philo_setting->time_start_us) / 1000);
}

int	philo_printf(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->philo_setting->death_mutex);
	if (philo->philo_setting->if_dead != NO_ONE_DEAD)
	{
		pthread_mutex_unlock(&philo->philo_setting->death_mutex);
		return (0);
	}
	philo->philo_setting->if_dead = NO_ONE_DEAD;
	if (status == SLEEP)
		printf("%d\t%d is sleeping\n",
			philo_timestamp(philo), philo->index + 1);
	else if (status == EAT)
		printf("%d\t%d is eating\n",
			philo_timestamp(philo), philo->index + 1);
	else if (status == THINK)
		printf("%d\t%d is thinking\n", philo_timestamp(philo),
			philo->index + 1);
	else if (status == FORK)
		printf("%d\t%d has taken a fork\n",
			philo_timestamp(philo), philo->index + 1);
	pthread_mutex_unlock(&philo->philo_setting->death_mutex);
	return (1);
}
