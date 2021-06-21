/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:09:40 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/22 05:05:44 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"
#include <stdio.h>

void		client_connect(int signo)
{
	if (signo == SIGUSR1)
	{

	}
	else
		;
}

void		client_init_struct(void)
{
	sigact_cli_connect.sa_flags = 0;
	sigemptyset(&sigact_cli_connect.sa_mask);
	sigact_cli_connect.sa_handler = client_connect;
}

static void	client_validate(int pid, char *str)
{
	if (pid < 101 || pid > 99999)
	{
		ft_putstr_fd("Invalid PID!\n", 1);
		exit(1);
	}
	if (*str == 0)
	{
		ft_putstr_fd("Too short string!\n", 1);
		exit(1);
	}
}

int 		main(int argc, char *argv[])
{
	int pid;
	if (argc != 3)
	{
		ft_putstr_fd("Invalid argument number!\n", 1);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	printf("My pid : %d\n", getpid());
	client_validate(pid, argv[2]);
	client_init_struct();
	sigaction(SIGUSR1, &sigact_cli_connect, 0);
	kill(pid, SIGUSR1);
	while (1)
		usleep(500000);
}
