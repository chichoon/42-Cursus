/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:09:40 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/28 21:15:37 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

t_data_tosend		g_data_tosend;
unsigned long long	g_lastupdate_signal;

void		kill_and_pause(pid_t pid, int signo)
{
	g_lastupdate_signal = signo;
	kill(pid, signo);
	usleep(50);
}

void		client_connect(int signo)
{
	if (signo == SIGUSR1)
	{
		g_lastupdate = g_count;
		sigaction(SIGUSR1, &sigact_cli_length, 0);
		ft_putstr_fd("Connected with server pid ", 1);
		ft_putnbr_fd(g_data_tosend.pid, 1);
		ft_putchar_fd('\n', 1);
		kill_and_pause(g_data_tosend.pid, SIGUSR1);
	}
}

void		client_init_struct(void)
{
	sigact_cli_connect.sa_flags = 0;
	sigemptyset(&sigact_cli_connect.sa_mask);
	sigact_cli_connect.sa_handler = client_connect;
	sigact_cli_length.sa_flags = 0;
	sigemptyset(&sigact_cli_length.sa_mask);
	sigact_cli_length.sa_handler = client_send_length;
	sigact_cli_string.sa_flags = 0;
	sigemptyset(&sigact_cli_string.sa_mask);
	sigact_cli_string.sa_handler = client_send_string;
}

unsigned long long g_count = 0;
unsigned long long g_lastupdate = 0;

int			main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_putstr_fd("Invalid argument number!\n", 1);
		exit(1);
	}
	g_data_tosend.pid = ft_atoi(argv[1]);
	g_data_tosend.length = ft_strlen(argv[2]);
	g_data_tosend.str = argv[2];
	if (g_data_tosend.pid < 101 || g_data_tosend.pid > 99999)
	{
		ft_putstr_fd("Invalid PID!\n", 1);
		exit(1);
	}
	client_init_struct();
	sigaction(SIGUSR1, &sigact_cli_connect, 0);
	kill_and_pause(g_data_tosend.pid, SIGUSR1);
	while (1)
	{
		g_count++;
		if(g_lastupdate + 10000 >= g_count)
		{
			//signal die
			send_last_signal();
			kill(srvpid, g_lastupdate_signal);
		}
		usleep(1);
	}
}
