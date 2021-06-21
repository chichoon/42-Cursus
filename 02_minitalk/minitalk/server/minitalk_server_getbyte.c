/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server_getbyte.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 04:33:56 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/22 04:35:37 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"

static void	server_get_length_if(int signo)
{
	if (signo == SIGUSR1)
	{
		g_client_data.length |= 0;
		g_client_data.length <<= 1;
	}
	else if (signo == SIGUSR2)
	{
		g_client_data.length |= 1;
		g_client_data.length <<= 1;
	}
}

void		server_get_length(int signo)
{
	static int total_bits;

	if (total_bits < 32)
		server_get_length_if(signo);
	else if (total_bits == 32)
	{
		total_bits = 0;
		sigaction(SIGUSR1, &sigact_string, 0);
		sigaction(SIGUSR2, &sigact_string, 0);
		g_client_data.str = (char *)malloc(sizeof(char) *
			(g_client_data.length + 1));
	}
}

static char	server_get_string_if(int signo, char c)
{
	if (signo == SIGUSR1)
	{
		c |= 0;
		c <<= 1;
	}
	else if (signo == SIGUSR2)
	{
		c |= 1;
		c <<= 1;
	}
	return c;
}

void		server_get_string(int signo)
{
	static char	char_temp;
	static int	len_bit;
	static int	len_byte;

	if (len_byte < g_client_data.length)
	{
		if (len_bit++ < 8)
			char_temp = server_get_char_if(signo, char_temp);
		else if (len_bit == 8)
		{
			len_bit = 0;
			char_temp = 0;
			g_client_data.str[len_byte++] = char_temp;
		}
	}
	else if (len_byte == g_client_data.length)
	{
		g_client_data.str[len_byte] = 0;
		write(1, g_client_data.str, g_client_data.length);
		free(g_client_data.str);
		len_byte = 0;
		sigaction(SIGUSR1, &sigact_connect, 0);
		sigaction(SIGUSR2, &sigact_connect, 0);
	}
}
