/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server_getbyte_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 04:33:56 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/26 17:32:51 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server_bonus.h"

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

void	server_get_string(int signo, siginfo_t *info, void *ptr)
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
		sigaction(SIGUSR1, &(g_data_receive.g_sigact_srv_try_connect), 0);
		sigaction(SIGUSR2, &(g_data_receive.g_sigact_srv_try_connect), 0);
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

void	server_get_length(int signo, siginfo_t *info, void *ptr)
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
		sigaction(SIGUSR1, &(g_data_receive.g_sigact_srv_string), 0);
		sigaction(SIGUSR2, &(g_data_receive.g_sigact_srv_string), 0);
		kill(g_data_receive.pid, SIGUSR1);
	}
}
