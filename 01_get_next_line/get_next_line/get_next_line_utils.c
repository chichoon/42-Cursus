/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:26:06 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/08 18:21:33 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (*s)
	{
		s++;
		length++;
	}
	return (length);
}

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		length;

	length = ft_strlen(src);
	ptr = (char *)malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (0);
	while (*src)
		*ptr++ = *src++;
	*ptr = 0;
	return (ptr - length);
}

char	*ft_strndup(char *str, int length)
{
	char	*ptr;
	char	*ptr_backup;

	ptr = (char *)malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (0);
	ptr_backup = ptr;
	while (length--)
		*ptr++ = *str++;
	*ptr = 0;
	return (ptr_backup);
}

char	*ft_strchr(const char *src, int c)
{
	char ch;

	ch = (char)c;
	while (*src)
	{
		if (*src == ch)
			break ;
		src++;
	}
	if (ch == 0 || *src == ch)
		return ((char *)src);
	else
		return (0);
}
