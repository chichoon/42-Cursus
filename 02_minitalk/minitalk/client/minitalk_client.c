/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:09:40 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/21 22:06:47 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"
#include <stdio.h>

void	minit_connect(char *pid, char *string)
{
	int	pid_int;

	pid_int = ft_atoi(pid);
	kill(pid_int, SIGUSR1);

	while (*string)
	{
		printf("%x", *string & 0xFF);
		string++;
	}
}

int 	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_putstr_fd("Invalid argument number!\n", 1);
		exit(1);
	}
	minit_connect(argv[1], argv[2]);
}
