/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:09:40 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/27 11:18:27 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

void	kill_and_pause(pid_t pid, int signo)
{
	kill(pid, signo);
	usleep(30);
}

void	client_send_bytes(int pid, char *string)
{
	int	length;
	int	byte_index;
	int	bit_index;
	int	bit_temp;

	length = ft_strlen(string);
	byte_index = 0;
	while (byte_index < length)
	{
		bit_index = 0;
		while (bit_index < 8)
		{
			bit_temp = string[byte_index] >> (7 - bit_index) & 1;
			if (bit_temp == 0)
				kill_and_pause(pid, SIGUSR1);
			else if (bit_temp == 1)
				kill_and_pause(pid, SIGUSR2);
			bit_index++;
		}
		usleep(300);
		byte_index++;
	}
	exit(0);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Invalid argument number!\n", 1);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 101 || pid > 99999)
	{
		ft_putstr_fd("Invalid PID!\n", 1);
		exit(1);
	}
	client_send_bytes(pid, argv[2]);
}
