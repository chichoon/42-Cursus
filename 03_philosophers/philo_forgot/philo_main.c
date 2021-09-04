/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:37:13 by jiychoi           #+#    #+#             */
/*   Updated: 2021/08/06 13:30:32 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosophers(t_philo_struct *philo_struct)
{
	struct timeval	tp;
	int				index;

	index = 0;
	while (index < 10)
	{
		gettimeofday(&tp, NULL);
		printf("Current time: %d\n", tp.tv_usec);
		index++;
	}
}

int	main(int argc, char *argv[])
{
	t_philo_struct	*philo_struct;

	if (argc != 5 && argc != 6)
	{
		printf("Too few arguments to call. Stop.\n");
		return (0);
	}
	philo_struct = philo_init_struct(argc, argv);
	if (!philo_struct)
	{
		printf("Initialization Failed. Stop.\n");
		return (0);
	}
	philosophers(philo_struct);
	return (0);
}
