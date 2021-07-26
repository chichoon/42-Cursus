/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:09:48 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/26 18:01:16 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"

/*
	** Minitalk Client: function to send bits (length & string)
*/
void	client_send_bytes(int pid, char *string);

/*
	** Minitalk Client: function to connect & initialize
*/
void	kill_and_pause(pid_t pid, int signo);

#endif
