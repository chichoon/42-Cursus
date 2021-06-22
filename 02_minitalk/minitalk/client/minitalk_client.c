/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:09:40 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/22 13:01:03 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"
#include <stdio.h>

t_data_tosend	g_data_tosend;

void		client_connect(int signo)
{
	if (signo == SIGUSR1)
	{
		sigaction(SIGUSR1, &sigact_cli_length, 0);
		sigaction(SIGUSR2, &sigact_cli_length, 0);
		kill(g_data_tosend.pid, SIGUSR1);
		printf("%d\n", g_data_tosend.length);
	}
	else if (signo == SIGUSR2)
	{
		usleep(500000);
		kill(g_data_tosend.pid, SIGUSR1);
	}
}

void		client_send_length(int signo)
{
	static int total_bits;

	if (total_bits < 32 && signo == SIGUSR1)
	{
		if ((g_data_tosend.length >> (31 - total_bits) & 1) == 0)
			kill(g_data_tosend.pid, SIGUSR1);
		else if ((g_data_tosend.length >> (31 - total_bits) & 1) == 1)
			kill(g_data_tosend.pid, SIGUSR2);
		total_bits++;
	}
	if (total_bits == 32)
	{
		total_bits = 0;
		sigaction(SIGUSR1, &sigact_cli_string, 0);
		sigaction(SIGUSR2, &sigact_cli_string, 0);
		printf("all length bits sent\n");
	}
}

void		client_send_string(int signo)
{
	static int	total_bits;
	static int	total_bytes;
	char		char_temp;

	printf("1\n");
	if (total_bytes < g_data_tosend.length && signo == SIGUSR1)
	{
		if (total_bits < 8)
		{
			printf("sigsig\n");
			char_temp = g_data_tosend.str[total_bytes];
			if ((char_temp >> (7 - total_bits) & 1) == 0)
				kill(g_data_tosend.pid, SIGUSR1);
			else if ((char_temp >> (7 - total_bits) & 1) == 1)
				kill(g_data_tosend.pid, SIGUSR2);
			total_bits++;
		}
		if (total_bits == 8)
		{
			total_bits = 0;
			total_bytes++;
		}
	}
	if (total_bytes == g_data_tosend.length)
	{
		printf("all string sent!\n");
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
	kill(g_data_tosend.pid, SIGUSR1);
	while (1)
		usleep(500000);
}
