/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 05:27:42 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/19 00:09:49 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*ptr_backup;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (0);
	len_s1 = 0;
	len_s2 = 0;
	while (s1[len_s1])
		len_s1++;
	while (s2[len_s2])
		len_s2++;
	ptr = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!ptr)
		return (0);
	ptr_backup = ptr;
	ft_memcpy(ptr, s1, len_s1);
	ptr += len_s1;
	ft_memcpy(ptr, s2, len_s2);
	ptr += len_s2;
	*ptr = 0;
	return (ptr_backup);
}

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		length;

	length = 0;
	while (src[length])
		length++;
	ptr = (char *)malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (0);
	while (*src)
		*ptr++ = *src++;
	*ptr = 0;
	return (ptr - length);
}

char	*ft_strchr(const char *src, int c)
{
	char	ch;

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
