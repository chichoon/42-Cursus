/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 05:27:13 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/09 08:57:09 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_get_oneline(int fd, char **line, char **str_buf, char *temp_buf)
{
	int		len_line;
	char	*temp_ptr;

	temp_ptr = ft_strjoin(str_buf[fd], temp_buf);
	if (!temp_ptr)
		return (-1);
	free(str_buf[fd]);
	str_buf[fd] = temp_ptr;
	temp_ptr = ft_strchr(str_buf[fd], '\n');
	if (temp_ptr)
	{
		len_line = temp_ptr - str_buf[fd];
		*line = ft_strndup(str_buf[fd], len_line);
		temp_ptr = ft_strdup(str_buf[fd] + len_line + 1);
		if (!temp_ptr)
			return (-1);
		free(str_buf[fd]);
		str_buf[fd] = temp_ptr;
		return (1);
	}
	return (0);
}

static int	gnl_read(int fd, char **line, char **str_buf)
{
	char	temp_buf[BUFFER_SIZE + 1];
	int		output;
	int		len_read;

	temp_buf[BUFFER_SIZE] = 0;
	len_read = read(fd, temp_buf, BUFFER_SIZE);
	while (len_read > 0)
	{
		output = gnl_get_oneline(fd, line, str_buf, temp_buf);
		if (output == -1 || output == 1)
			return (output);
	}
	if (len_read < 0)
		return (-1);
	
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*str_buf[256];
	int			output;

	if (BUFFER_SIZE < 1 || fd > 256 || fd < 0 || !line)
		return (-1);
	if (!str_buf[fd])
		str_buf[fd] = ft_strdup("");
	output = gnl_read(fd, line, str_buf);
	if (!*line || output == -1)
		return (-1);
	if (output == 1)
		return (1);
	free(str_buf[fd]);
	str_buf[fd] = 0;
	return (0);
}

#include <fcntl.h>
int	main(void)
{
	char **line;
	char *tmp = "";
	line = &tmp;
	int index = 0;
	int fd = open("test.txt", O_RDONLY);
	while (get_next_line(fd, line) > 0)
		printf("str %d: %s......\n", index++, *line);
	printf("str %d: %s(EOF)\n", index, *line);
}
