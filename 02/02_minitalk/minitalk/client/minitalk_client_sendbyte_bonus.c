/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client_sendbyte_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 04:36:24 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/28 16:16:53 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client_bonus.h"

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
