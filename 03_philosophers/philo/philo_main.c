/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:37:13 by jiychoi           #+#    #+#             */
/*   Updated: 2021/08/03 12:57:40 by jiychoi          ###   ########.fr       */
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
		return (philo_print_and_return("Too few arguments to call. Stop.\n"));
	philo_struct = philo_init_struct(argc, argv);
	if (!philo_struct)
		return (philo_print_and_return("Initialization Failed. Stop.\n"));
	philosophers(philo_struct);
	return (0);
}
