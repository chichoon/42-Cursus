/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:29:23 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/19 16:19:19 by jiychoi          ###   ########.fr       */
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
