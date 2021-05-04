/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:54:08 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 21:12:39 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (i + 1 < n)
	{
		if (!*src)
			break ;
		else
		{
			*dst++ = *src++;
			i++;
		}
	}
	while (*src)
	{
		i++;
		src++;
	}
	if (n != 0)
		*dst = '\0';
	return (i);
}
