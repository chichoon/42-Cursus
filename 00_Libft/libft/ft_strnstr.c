/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:05:28 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 18:13:17 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *to_find, size_t n)
{
	char *tmp;
	char *tmp_find;

	if (!*to_find)
		return ((char *)src);
	while (1)
	{
		tmp_find = (char *)to_find;
		while (*src != *to_find)
			if (!*src++ || !n--)
				return (0);
		tmp = (char *)src;
		while (*tmp_find)
		{
			if (*src != *tmp_find)
				break ;
			if (!n--)
				return (0);
			src++;
			tmp_find++;
		}
		if (!*tmp_find)
			break ;
	}
	return (tmp);
}
