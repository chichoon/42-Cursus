/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:29:44 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/08 21:08:10 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_line(char *buf, int *check_eof)
{
	char	*newline_ptr;
	int		len_line;

	newline_ptr = ft_strchr(buf, '\n');
	len_line = 0;
	while (buf < newline_ptr && *buf)
	{
		buf++;
		len_line++;
	}
	if (!*buf)
		*check_eof = 0;
	return (len_line);
} //return length of the line

int	ft_read_file(int fd, char *buf, char *line_rest)
{
	int	len_file;

	len_file = read(fd, buf, BUFFER_SIZE);
	if (len_file < 0)
		return (-1);
	buf[len_file] = 0;
	line_rest = ft_strdup(buf);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*line_rest[256];
	char		temp_buf[BUFFER_SIZE];
	int			len_line;
	int			*check_eof;
	char		*line_read;
	/*
		** if array doesn't work, use malloc.
	*/
	if (BUFFER_SIZE < 1 || !line || fd > 256 || fd < 0)
		return (-1);
	check_eof = 1;
	if (!line_rest[fd])
		ft_read_file(fd, temp_buf, line_rest[fd]);
	len_line = ft_read_line(line_rest[fd], check_eof);
	*line = ft_strndup(line_rest[fd], len_line);
	if (!*check_eof)
	{
		free(line_rest[fd]);
		return (0);
	}
	temp_buf += len_line;
	temp_buf++;
	ft_strcpy(line_rest[fd], temp_buf);
	return (1);
}
