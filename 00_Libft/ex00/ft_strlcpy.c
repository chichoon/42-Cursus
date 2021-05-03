/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:54:08 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 17:13:04 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t n)
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
	*dst = '\0';
	return (i);
}
