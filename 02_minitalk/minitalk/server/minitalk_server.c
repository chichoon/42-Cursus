/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:27:39 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/21 20:03:09 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"
#include <stdio.h>

void	minit_getsig(int signo)
{
	if (signo == SIGUSR1)
		printf("Received SIGUSR1.\n");
	else if (signo == SIGUSR2)
		printf("Received SIGUSR2.\n");
}

int		main(void)
{
	char *pid;

	pid = ft_itoa(getpid());
	ft_putstr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	if (signal(SIGUSR1, minit_getsig) == SIG_ERR)
		perror("Can't catch SIGUSR1\n");
	if (signal(SIGUSR2, minit_getsig) == SIG_ERR)
		perror("Can't catch SIGUSR2\n");
	while (1)
	{
		usleep(500000);
	}
	free(pid);
}
