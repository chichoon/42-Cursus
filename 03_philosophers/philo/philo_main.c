/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:37:13 by jiychoi           #+#    #+#             */
/*   Updated: 2021/08/03 11:13:57 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosophers(void)
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
	if (argc != 5 && argc != 6)
		return (philo_print_and_return("Too few arguments to call. Stop.\n"));
	//if (!philo_init(philo_set, argc, argv))
	//	return (philo_print_and_return("Initialization Failed. Stop.\n"));
	philosophers();
	return (0);
}
