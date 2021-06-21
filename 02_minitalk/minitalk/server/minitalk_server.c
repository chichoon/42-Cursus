/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:27:39 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/22 05:03:05 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"
#include <stdio.h>

t_client_data	g_client_data;

void	minit_getsig(int signo)
{
	if (signo == SIGUSR1)
		printf("Received SIGUSR1.\n");
	else if (signo == SIGUSR2)
		printf("Received SIGUSR2.\n");
}

void	server_connect(int signo)
{
	if (signo == SIGUSR1)
	{
		sigaction(SIGUSR1, &sigact_srv_length, 0);
		sigaction(SIGUSR2, &sigact_srv_length, 0);
	}
}

void	server_try_connect(int signo, siginfo_t *info, void *ptr)
{
	ptr = (char *)ptr;
	if(signo == SIGUSR1)
	{
		if (g_client_data.pid == 0)
		{
			g_client_data.pid = info->si_pid;
			sigaction(SIGUSR1, &sigact_srv_try_connect, 0);
			kill(g_client_data.pid, SIGUSR1);
		}
	}
}

void	server_init_struct(void)
{
	sigact_srv_try_connect.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact_srv_try_connect.sa_mask);
	sigact_srv_try_connect.sa_sigaction = server_try_connect;
	/*
	sigact_srv_connect.sa_flags = 0;
	sigemptyset(&sigact_srv_connect.sa_mask);
	sigact_srv_connect.sa_handler = server_connect;
	sigact_srv_length.sa_flags = 0;
	sigemptyset(&sigact_srv_length.sa_mask);
	sigact_srv_length.sa_handler = server_get_length;
	sigact_srv_string.sa_flags = 0;
	sigemptyset(&sigact_srv_string.sa_mask);
	sigact_srv_string.sa_handler = server_get_string;
	*/
	g_client_data.pid = 0;
	g_client_data.length = 0;
}

int		main(void)
{
	ft_putstr_fd("SERVER PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	server_init_struct();
	sigaction(SIGUSR1, &sigact_srv_try_connect, 0);
	while (1)
		usleep(500000);
}
