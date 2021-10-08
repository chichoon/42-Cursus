/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:05:28 by jiychoi           #+#    #+#             */
/*   Updated: 2021/10/07 22:52:04 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_pipe.h"

char	*ft_strnstr(const char *src, const char *to_find, size_t n)
{
	char	*tmp;
	char	*tmp_find;

	if (!*to_find)
		return ((char *)src);
	while (1)
	{
		tmp_find = (char *)to_find;
		while (*src != *to_find || !n)
			if (!*src++ || !n--)
				return (0);
		tmp = (char *)src;
		while (*tmp_find)
		{
			if (*src != *tmp_find || !n--)
				break ;
			src++;
			tmp_find++;
		}
		if (!*tmp_find)
			break ;
		if (*to_find == *(to_find + 1))
			src = tmp + 1;
	}
	return (tmp);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*tmp;
	char	*tmp_find;

	if (!*to_find)
		return (str);
	while (1)
	{
		tmp_find = to_find;
		while (*str != *tmp_find)
		{
			if (!*str++)
				return (0);
		}
		tmp = str;
		while (*tmp_find)
		{
			if (*str != *tmp_find)
				break ;
			str++;
			tmp_find++;
		}
		if (!*tmp_find)
			break ;
	}
	return (tmp);
}
