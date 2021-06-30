/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:27:32 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/30 23:29:10 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_SERVER_BONUS_H
# define MINITALK_SERVER_BONUS_H

# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"

struct sigaction		g_sigact_srv_try_connect;
struct sigaction		g_sigact_srv_connect;
struct sigaction		g_sigact_srv_length;
struct sigaction		g_sigact_srv_string;
extern t_data_receive	g_data_receive;

typedef struct s_data_receive
{
	pid_t			pid;
	int				length;
	unsigned char	char_temp;
	char			*str;
}					t_data_receive;

/*
	** Minitalk Server: function to connect & initialize
*/
void				server_reset_status(void);
void				server_connect(int signo, siginfo_t *info, void *ptr);
void				server_try_connect(int signo, siginfo_t *info, void *ptr);
void				server_init_struct(void);

/*
	** Minitalk Server: function to receive bits (length & string)
*/
void				server_get_string(int signo, siginfo_t *info, void *ptr);
void				server_get_length(int signo, siginfo_t *info, void *ptr);

#endif
