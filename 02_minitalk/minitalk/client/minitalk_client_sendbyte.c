/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client_sendbyte.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 04:36:24 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/22 04:37:18 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

int		client_ackstr(int signo)
{
	if (signo == SIGUSR1)
		return (0);
	else if (signo == SIGUSR2)
		return (1);
	return (-1);
}

void	client_sendstr(int pid, char *string)
{
	char	c;
	int		int_shift;
	int		bit_to_send;

	while (*string)
	{
		c = *string;
		int_shift = 8;
		while (--int_shift >= 0)
		{
			bit_to_send = c >> int_shift & 0x1;
			if (!bit_to_send)
			{
				kill(pid, SIGUSR1);
			}
			else
				kill(pid, SIGUSR2);
		}
	}
}
