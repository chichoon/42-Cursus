/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:09:40 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/24 23:32:38 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"
#include <stdio.h>

t_data_tosend	g_data_tosend;

void		kill_and_pause(pid_t pid, int signo)
{
	kill(pid, signo);
	usleep(80);
}

void		client_connect(int signo)
{
	if (signo == SIGUSR1)
	{
		sigaction(SIGUSR1, &sigact_cli_length, 0);
		ft_putstr_fd("Connected with server pid ", 1);
		ft_putnbr_fd(g_data_tosend.pid, 1);
		ft_putchar_fd('\n', 1);
		kill_and_pause(g_data_tosend.pid, SIGUSR1);
	}
}

void		client_send_length(int signo)
{
	static int total_bits;

	if (total_bits < 32 && signo == SIGUSR1)
	{
		if ((g_data_tosend.length >> (31 - total_bits) & 1) == 0)
			kill_and_pause(g_data_tosend.pid, SIGUSR1);
		else if ((g_data_tosend.length >> (31 - total_bits) & 1) == 1)
			kill_and_pause(g_data_tosend.pid, SIGUSR2);
		total_bits++;
	}
	if (total_bits == 32 && signo == SIGUSR1)
	{
		ft_putstr_fd("Sending length successful.\n", 1);
		total_bits = 0;
		sigaction(SIGUSR1, &sigact_cli_string, 0);
	}
}

void		client_send_string(int signo)
{
	static int		total_bits;
	static int		total_bytes;
	int				bit_temp;

	if (total_bits == 8)
	{
		total_bits = 0;
		total_bytes++;
	}
	if (total_bytes < g_data_tosend.length && signo == SIGUSR1)
	{
		bit_temp = g_data_tosend.str[total_bytes] >> (7 - total_bits) & 1;
		total_bits++;
		if (bit_temp == 0)
			kill_and_pause(g_data_tosend.pid, SIGUSR1);
		else if (bit_temp == 1)
			kill_and_pause(g_data_tosend.pid, SIGUSR2);
	}
	if (total_bytes == g_data_tosend.length && signo == SIGUSR1)
	{
		total_bytes = 0;
		kill(g_data_tosend.pid, SIGUSR1);
		exit(0);
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
	client_validate(g_data_tosend.pid, argv[2]);
	client_init_struct();
	sigaction(SIGUSR1, &sigact_cli_connect, 0);
	kill_and_pause(g_data_tosend.pid, SIGUSR1);
	while (1)
		usleep(500000);
}
