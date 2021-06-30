/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:29:44 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/30 23:04:21 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_read_line(char *buf, int *check_eof)
{
	char	*newline_ptr;
	int		len_line;

	newline_ptr = ft_strchr(buf, '\n');
	len_line = 0;
	if (!newline_ptr)
	{
		while (*buf)
		{
			buf++;
			len_line++;
		}
		*check_eof = 0;
		return (len_line);
	}
	else
	{
		while (buf < newline_ptr)
		{
			buf++;
			len_line++;
		}
		return (len_line);
	}
}

static int	read_until_eof(int fd, char *temp_read)
{
	char	temp_buf[BUFFER_SIZE + 1];
	int		len_read;
	int		len_file;

	len_file = 0;
	len_read = read(fd, temp_buf, BUFFER_SIZE);
	temp_buf[BUFFER_SIZE] = 0;
	while (len_read > 0)
	{
		ft_strcpy(&temp_read[len_file], temp_buf);
		len_file += len_read;
		len_read = read(fd, temp_buf, BUFFER_SIZE);
	}
	if (len_read < 0)
		return (-1);
	temp_read[len_file] = 0;
	return (0);
}

static int	gnl_initial(int fd, char **line, char **line_rest)
{
	char	temp_read[8000000];
	int		len_file;
	int		len_line;
	int		check_eof;

	check_eof = 1;
	len_file = 0;
	if (read_until_eof(fd, temp_read) < 0)
		return (-1);
	*line_rest = ft_strdup(temp_read);
	len_line = ft_read_line(temp_read, &check_eof);
	*line = ft_strndup(temp_read, len_line);
	if (!check_eof)
	{
		free(line_rest[fd]);
		line_rest[fd] = 0;
		return (0);
	}
	line_rest[fd] = ft_strdup(&temp_read[len_line + 1]);
	return (1);
}

static int	gnl(int fd, char **line, char **line_rest)
{
	int		len_line;
	int		check_eof;
	char	*str_backup;

	check_eof = 1;
	len_line = ft_read_line(line_rest[fd], &check_eof);
	*line = ft_strndup(line_rest[fd], len_line);
	if (!check_eof)
	{
		free(line_rest[fd]);
		line_rest[fd] = 0;
		return (0);
	}
	str_backup = ft_strdup(&line_rest[fd][len_line + 1]);
	ft_strcpy(line_rest[fd], str_backup);
	free(str_backup);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*line_rest[256];

	if (BUFFER_SIZE < 1 || !line || fd > 256 || fd < 0)
		return (-1);
	if (!line_rest[fd])
		return (gnl_initial(fd, line, line_rest));
	else
		return (gnl(fd, line, line_rest));
}
