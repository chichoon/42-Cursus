/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:09:48 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/28 16:17:01 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_BONUS_H
# define MINITALK_CLIENT_BONUS_H

# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"

struct sigaction	sigact_cli_connect;
struct sigaction	sigact_cli_length;
struct sigaction	sigact_cli_string;

typedef struct		s_data_tosend
{
	pid_t	pid;
	int		length;
	char	*str;
}					t_data_tosend;

extern t_data_tosend g_data_tosend;

/*
	** Minitalk Client: function to send bits (length & string)
*/
void				client_send_length(int signo);
void				client_send_string(int signo);

/*
	** Minitalk Client: function to connect & initialize
*/
void				client_connect(int signo);
void				kill_and_pause(pid_t pid, int signo);
void				client_init_struct(void);

#endif
