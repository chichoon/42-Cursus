/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:11:33 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/08 21:10:25 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int	get_next_line(int fd, char **line);
int	ft_read_file(int fd, char *buf, char *line_rest);
int	ft_read_line(char *buf, int *check_eof);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strndup(char *str, int length);
char	*ft_strchr(const char *src, int c);

#endif
