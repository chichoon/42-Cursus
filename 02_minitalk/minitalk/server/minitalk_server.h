/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:27:32 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/22 12:56:52 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_SERVER_H
# define MINITALK_SERVER_H

# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"

struct sigaction	sigact_srv_try_connect;
struct sigaction	sigact_srv_connect;
struct sigaction	sigact_srv_length;
struct sigaction	sigact_srv_string;

typedef struct		s_data_receive
{
	pid_t	pid;
	int		length;
	char	*str;
}					t_data_receive;

extern t_data_receive g_data_receive;

#endif
