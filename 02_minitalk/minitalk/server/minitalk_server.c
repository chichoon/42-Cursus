/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:27:39 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/24 23:32:27 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"
#include <stdio.h>

t_data_receive	g_data_receive;

void		server_reset_status(void)
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

static void	server_get_string_if(int signo, int len_bit)
{
	if (signo == SIGUSR1)
	{
		g_data_receive.char_temp |= 0;
		if (len_bit < 7)
			g_data_receive.char_temp <<= 1;
	}
	else if (signo == SIGUSR2)
	{
		g_data_receive.char_temp |= 1;
		if (len_bit < 7)
			g_data_receive.char_temp <<= 1;
	}
}

void		server_get_string(int signo, siginfo_t *info, void *ptr)
{
	static int				len_bit;
	static int				len_byte;

	ptr = (char *)ptr;
	if (len_bit == 8)
	{
		len_bit = 0;
		g_data_receive.str[len_byte++] = g_data_receive.char_temp;
		g_data_receive.char_temp = 0;
	}
	if (len_byte < g_data_receive.length && g_data_receive.pid == info->si_pid)
	{
		server_get_string_if(signo, len_bit++);
		kill(g_data_receive.pid, SIGUSR1);
	}
	if (len_byte == g_data_receive.length && g_data_receive.pid == info->si_pid)
	{
		server_reset_status();
		len_byte = 0;
		sigaction(SIGUSR1, &sigact_srv_try_connect, 0);
		sigaction(SIGUSR2, &sigact_srv_try_connect, 0);
	}
}

static void	server_get_length_if(int signo, int len_bit)
{
	if (signo == SIGUSR1)
	{
		g_data_receive.length |= 0;
		if (len_bit < 31)
			g_data_receive.length <<= 1;
		kill(g_data_receive.pid, SIGUSR1);
	}
	else if (signo == SIGUSR2)
	{
		g_data_receive.length |= 1;
		if (len_bit < 31)
			g_data_receive.length <<= 1;
		kill(g_data_receive.pid, SIGUSR1);
	}
}

void		server_get_length(int signo, siginfo_t *info, void *ptr)
{
	static int	len_bit;
	char		*str_ptr;

	ptr = (char *)ptr;
	if (len_bit < 32 && g_data_receive.pid == info->si_pid)
		server_get_length_if(signo, len_bit++);
	if (len_bit == 32 && g_data_receive.pid == info->si_pid)
	{
		len_bit = 0;
		str_ptr = (char *)malloc(sizeof(char) * (g_data_receive.length + 1));
		if (!str_ptr)
		{
			ft_putstr_fd("Malloc failed. Exit server.\n", 1);
			exit(1);
		}
		g_data_receive.str = str_ptr;
		sigaction(SIGUSR1, &sigact_srv_string, 0);
		sigaction(SIGUSR2, &sigact_srv_string, 0);
		kill(g_data_receive.pid, SIGUSR1);
	}
}

void		server_connect(int signo, siginfo_t *info, void *ptr)
{
	ptr = (char *)ptr;
	if (signo == SIGUSR1 && g_data_receive.pid == info->si_pid)
	{
		sigaction(SIGUSR1, &sigact_srv_length, 0);
		sigaction(SIGUSR2, &sigact_srv_length, 0);
		kill(g_data_receive.pid, SIGUSR1);
	}
}

void		server_try_connect(int signo, siginfo_t *info, void *ptr)
{
	ptr = (char *)ptr;
	if (signo == SIGUSR1 && g_data_receive.pid == 0)
	{
		g_data_receive.pid = info->si_pid;
		ft_putstr_fd("Connected with pid ", 1);
		ft_putnbr_fd(g_data_receive.pid, 1);
		ft_putchar_fd('\n', 1);
		sigaction(SIGUSR1, &sigact_srv_connect, 0);
		sigaction(SIGUSR2, &sigact_srv_connect, 0);
		kill(g_data_receive.pid, SIGUSR1);
	}
}

void	server_init_struct(void)
{
	sigact_srv_try_connect.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact_srv_try_connect.sa_mask);
	sigact_srv_try_connect.sa_sigaction = server_try_connect;
	sigact_srv_connect.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact_srv_connect.sa_mask);
	sigact_srv_connect.sa_sigaction = server_connect;
	sigact_srv_length.sa_flags = 0;
	sigemptyset(&sigact_srv_length.sa_mask);
	sigact_srv_length.sa_sigaction = server_get_length;
	sigact_srv_string.sa_flags = 0;
	sigemptyset(&sigact_srv_string.sa_mask);
	sigact_srv_string.sa_sigaction = server_get_string;
	g_data_receive.pid = 0;
	g_data_receive.length = 0;
	g_data_receive.str = 0;
	g_data_receive.char_temp = 0;
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
