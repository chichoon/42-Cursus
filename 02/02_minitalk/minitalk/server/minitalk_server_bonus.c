/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:27:39 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/30 23:28:54 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server_bonus.h"

t_data_receive	g_data_receive;

void	server_reset_status(void)
{
	g_data_receive.str[g_data_receive.length] = 0;
	write(1, g_data_receive.str, g_data_receive.length);
	write(1, "\n", 1);
	free(g_data_receive.str);
	g_data_receive.pid = 0;
	g_data_receive.length = 0;
	g_data_receive.str = 0;
	g_data_receive.char_temp = 0;
}

void	server_connect(int signo, siginfo_t *info, void *ptr)
{
	ptr = (char *)ptr;
	if (signo == SIGUSR1 && g_data_receive.pid == info->si_pid)
	{
		sigaction(SIGUSR1, &g_sigact_srv_length, 0);
		sigaction(SIGUSR2, &g_sigact_srv_length, 0);
		kill(g_data_receive.pid, SIGUSR1);
	}
}

void	server_try_connect(int signo, siginfo_t *info, void *ptr)
{
	ptr = (char *)ptr;
	if (signo == SIGUSR1 && g_data_receive.pid == 0)
	{
		g_data_receive.pid = info->si_pid;
		ft_putstr_fd("Connected with pid ", 1);
		ft_putnbr_fd(g_data_receive.pid, 1);
		ft_putchar_fd('\n', 1);
		sigaction(SIGUSR1, &g_sigact_srv_connect, 0);
		sigaction(SIGUSR2, &g_sigact_srv_connect, 0);
		kill(g_data_receive.pid, SIGUSR1);
	}
}

void	server_init_struct(void)
{
	g_sigact_srv_try_connect.sa_flags = SA_SIGINFO;
	sigemptyset(&g_sigact_srv_try_connect.sa_mask);
	g_sigact_srv_try_connect.sa_sigaction = server_try_connect;
	g_sigact_srv_connect.sa_flags = SA_SIGINFO;
	sigemptyset(&g_sigact_srv_connect.sa_mask);
	g_sigact_srv_connect.sa_sigaction = server_connect;
	g_sigact_srv_length.sa_flags = SA_SIGINFO;
	sigemptyset(&g_sigact_srv_length.sa_mask);
	g_sigact_srv_length.sa_sigaction = server_get_length;
	g_sigact_srv_string.sa_flags = SA_SIGINFO;
	sigemptyset(&g_sigact_srv_string.sa_mask);
	g_sigact_srv_string.sa_sigaction = server_get_string;
	g_data_receive.pid = 0;
	g_data_receive.length = 0;
	g_data_receive.str = 0;
	g_data_receive.char_temp = 0;
}

int	main(void)
{
	ft_putstr_fd("SERVER PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	server_init_struct();
	sigaction(SIGUSR1, &g_sigact_srv_try_connect, 0);
	while (1)
		usleep(500000);
}
