/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:27:39 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/26 18:07:55 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"

void	server_get_bytes(int sig)
{
	static char	char_temp;
	static int	len_bit;

	if (sig == SIGUSR1)
	{
		char_temp |= 0;
		if (len_bit < 7)
			char_temp <<= 1;
	}
	else if (sig == SIGUSR2)
	{
		char_temp |= 1;
		if (len_bit < 7)
			char_temp <<= 1;
	}
	len_bit++;
	if (len_bit == 8)
	{
		write(1, &char_temp, 1);
		len_bit = 0;
		char_temp = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("SERVER PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, server_get_bytes);
	signal(SIGUSR2, server_get_bytes);
	while (1)
		usleep(500000);
}
