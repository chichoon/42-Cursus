/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:27:39 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/22 13:00:03 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"
#include <stdio.h>

t_data_receive	g_data_receive;

static char	server_get_string_if(int signo, char c, int len_bit)
{
	if (signo == SIGUSR1)
	{
		c |= 0;
		if (len_bit < 8)
			c <<= 1;
		kill(g_data_receive.pid, SIGUSR1);
	}
	else if (signo == SIGUSR2)
	{
		c |= 1;
		if (len_bit < 8)
			c <<= 1;
		kill(g_data_receive.pid, SIGUSR1);
	}
	return (c);
}

void		server_get_string(int signo)
{
	static char	char_temp;
	static int	len_bit;
	static int	len_byte;

	if (len_byte < g_data_receive.length)
	{
		if (len_bit++ < 8)
			char_temp = server_get_string_if(signo, char_temp, len_bit);
		else if (len_bit == 8)
		{
			len_bit = 0;
			char_temp = 0;
			g_data_receive.str[len_byte++] = char_temp;
		}
	}
	if (len_byte == g_data_receive.length)
	{
		g_data_receive.str[len_byte] = 0;
		write(1, g_data_receive.str, g_data_receive.length);
		free(g_data_receive.str);
		len_byte = 0;
		sigaction(SIGUSR1, &sigact_srv_connect, 0);
		sigaction(SIGUSR2, &sigact_srv_connect, 0);
	}
}

static void	server_get_length_if(int signo, int len_bit)
{
	if (signo == SIGUSR1)
	{
		g_data_receive.length |= 0;
		if (len_bit < 32)
			g_data_receive.length <<= 1;
		kill(g_data_receive.pid, SIGUSR1);
	}
	else if (signo == SIGUSR2)
	{
		g_data_receive.length |= 1;
		if (len_bit < 32)
			g_data_receive.length <<= 1;
		kill(g_data_receive.pid, SIGUSR1);
	}
}

void		server_get_length(int signo)
{
	static int len_bit;

	if (len_bit++ < 32)
		server_get_length_if(signo, len_bit);
	if (len_bit == 32)
	{
		printf("\nlength: %d\n", g_data_receive.length);
		len_bit = 0;
		sigaction(SIGUSR1, &sigact_srv_string, 0);
		sigaction(SIGUSR2, &sigact_srv_string, 0);
		g_data_receive.str = (char *)malloc(sizeof(char) *
			(g_data_receive.length + 1));
		kill(g_data_receive.pid, SIGUSR1);
	}
}

void		server_connect(int signo, siginfo_t *info, void *ptr)
{
	ptr = (char *)ptr;
	if (signo == SIGUSR1)
	{
		if (g_data_receive.pid == info->si_pid)
		{
			sigaction(SIGUSR1, &sigact_srv_length, 0);
			sigaction(SIGUSR2, &sigact_srv_length, 0);
			kill(g_data_receive.pid, SIGUSR1);
		}
		else
			kill(info->si_pid, SIGUSR2);
	}
}

void		server_try_connect(int signo, siginfo_t *info, void *ptr)
{
	ptr = (char *)ptr;
	if (signo == SIGUSR1)
	{
		if (g_data_receive.pid == 0)
		{
			g_data_receive.pid = info->si_pid;
			sigaction(SIGUSR1, &sigact_srv_try_connect, 0);
			ft_putstr_fd("Connected with pid ", 1);
			ft_putnbr_fd(g_data_receive.pid, 1);
			ft_putchar_fd('\n', 1);
			sigaction(SIGUSR1, &sigact_srv_connect, 0);
			sigaction(SIGUSR2, &sigact_srv_connect, 0);
			kill(g_data_receive.pid, SIGUSR1);
		}
		else
			kill(info->si_pid, SIGUSR2);
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
	sigact_srv_length.sa_handler = server_get_length;
	sigact_srv_string.sa_flags = 0;
	sigemptyset(&sigact_srv_string.sa_mask);
	sigact_srv_string.sa_handler = server_get_string;
	g_data_receive.pid = 0;
	g_data_receive.length = 0;
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
