/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:09:40 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/26 17:36:07 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client_bonus.h"

t_data_tosend	g_data_tosend;

void	kill_and_pause(pid_t pid, int signo)
{
	kill(pid, signo);
	usleep(50);
}

void	client_connect(int signo)
{
	if (signo == SIGUSR1)
	{
		sigaction(SIGUSR1, &(g_data_tosend.g_sigact_cli_length), 0);
		ft_putstr_fd("Connected with server pid ", 1);
		ft_putnbr_fd(g_data_tosend.pid, 1);
		ft_putchar_fd('\n', 1);
		kill_and_pause(g_data_tosend.pid, SIGUSR1);
	}
}

void	client_init_struct(void)
{
	g_data_tosend.g_sigact_cli_connect.sa_flags = 0;
	sigemptyset(&g_data_tosend.g_sigact_cli_connect.sa_mask);
	g_data_tosend.g_sigact_cli_connect.sa_handler = client_connect;
	g_data_tosend.g_sigact_cli_length.sa_flags = 0;
	sigemptyset(&g_data_tosend.g_sigact_cli_length.sa_mask);
	g_data_tosend.g_sigact_cli_length.sa_handler = client_send_length;
	g_data_tosend.g_sigact_cli_string.sa_flags = 0;
	sigemptyset(&g_data_tosend.g_sigact_cli_string.sa_mask);
	g_data_tosend.g_sigact_cli_string.sa_handler = client_send_string;
}

int	main(int argc, char *argv[])
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
	sigaction(SIGUSR1, &(g_data_tosend.g_sigact_cli_connect), 0);
	kill_and_pause(g_data_tosend.pid, SIGUSR1);
	while (1)
		usleep(500000);
}
