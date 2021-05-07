/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:26:06 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/07 13:56:29 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_open_file(int fd, char *buf)
{
	int length;

	length = read(fd, buf, BUFFER_SIZE);
	return (length);
}