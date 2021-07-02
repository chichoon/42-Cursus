/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:09:48 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/02 16:25:26 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_data_tosend
{
	pid_t	pid;
	int		length;
	char	*str;
}					t_data_tosend;

struct sigaction		g_sigact_cli_connect;
struct sigaction		g_sigact_cli_length;
struct sigaction		g_sigact_cli_string;
extern t_data_tosend	g_data_tosend;

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
