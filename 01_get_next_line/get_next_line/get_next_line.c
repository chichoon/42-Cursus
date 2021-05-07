/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:29:44 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/07 16:00:02 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_file(int length, char *buf, char **line)
{
	char	*newline_ptr;

	newline_ptr = ft_strchr(buf, '\n');
	while ()
} //return length of the line

int	get_next_line(int fd, char **line)
{
	static char	*line_rest;
	char		temp_buf[BUFFER_SIZE];
	int			len_file;
	int			len_line;
	char		*line_read;
	/*
		** if array doesn't work, use malloc.
	*/
	if (!BUFFER_SIZE)
		return (-1);

	len_file = read(fd, temp_buf, BUFFER_SIZE);
	ft_read_file(length, temp_buf, line);
	line_read = (char *)malloc(sizeof(char) * (length + 1));


}
