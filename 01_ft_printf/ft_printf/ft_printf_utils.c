/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:29:23 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/17 20:49:33 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

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

char	*ft_strnchr(const char *src, const char *dst, int c)
{
	char ch;

	ch = (char)c;
	while (src < dst && *src)
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

int		ft_write_until(const char *src, const char *dst)
{
	int index;

	index = 0;
	while (src < dst && *src)
	{
		write(1, src++, 1);
		index++;
	}
	return (index);
}

int		if_available(char s, char *arr)
{
	while (*arr)
	{
		if (*arr == s)
			return (1);
		arr++;
	}
	return (0);
}

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
