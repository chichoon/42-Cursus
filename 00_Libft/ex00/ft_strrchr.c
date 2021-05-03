/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:40:59 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 17:46:36 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	size_t	length;

	length = ft_strlen(src);
	src += length;
	while (length)
	{
		if (*src == c)
			return ((char *)src);
		src--;
		length--;
	}
	return (0);
}
