/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 05:27:13 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/30 22:56:10 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	free_static_buf(int fd, char **str_buf, char *init_ptr)
{
	free(str_buf[fd]);
	str_buf[fd] = init_ptr;
	return (-1);
}

static int	cut_next_line(int fd, char **line, char **str_buf)
{
	int		len_line;
	char	*ptr;

	ptr = ft_strchr(str_buf[fd], '\n');
	len_line = ptr - str_buf[fd];
	*line = ft_strndup(str_buf[fd], len_line);
	if (!*line)
		return (free_static_buf(fd, str_buf, 0));
	ptr = ft_strdup(str_buf[fd] + len_line + 1);
	free_static_buf(fd, str_buf, ptr);
	return (1);
}

int	read_bufsize(int fd, char **line, char **str_buf)
{
	char		temp_buf[BUFFER_SIZE + 1];
	int			len_read;
	char		*ptr;

	len_read = read(fd, temp_buf, BUFFER_SIZE);
	while (len_read > 0)
	{
		temp_buf[len_read] = 0;
		ptr = ft_strjoin(str_buf[fd], temp_buf);
		if (!ptr)
			return (free_static_buf(fd, str_buf, 0));
		free_static_buf(fd, str_buf, ptr);
		if (ft_strchr(str_buf[fd], '\n'))
			return (cut_next_line(fd, line, str_buf));
		len_read = read(fd, temp_buf, BUFFER_SIZE);
	}
	if (len_read < 0)
		return (free_static_buf(fd, str_buf, 0));
	if (ft_strchr(str_buf[fd], '\n'))
		return (cut_next_line(fd, line, str_buf));
	*line = ft_strdup(str_buf[fd]);
	free_static_buf(fd, str_buf, 0);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*str_buf[256];

	if (BUFFER_SIZE < 1 || fd > 256 || fd < 0 || !line)
		return (-1);
	if (!str_buf[fd])
		str_buf[fd] = ft_strdup("");
	return (read_bufsize(fd, line, str_buf));
}
