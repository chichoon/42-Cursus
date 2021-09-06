/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:02:18 by jiychoi           #+#    #+#             */
/*   Updated: 2021/09/06 18:18:34 by jiychoi          ###   ########.fr       */
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
		if ((*str >= '9' || *str <= '0')
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

// int	philo_printf(t_philo *philo, int condition)
// {
// 	//
// }
