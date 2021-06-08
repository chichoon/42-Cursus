/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:40:31 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/02/24 15:57:26 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

int				get_next_line(int fd, char **line);
//char			*gnl_set_data(char **out, char *src);
int				dispose_string(int fd, char **data, char **line, int offset);
//void			ft_memncpy(char *dest, char *src, int n);
//char			*ft_strncat(char *s1, char *s2, int n);

#endif
