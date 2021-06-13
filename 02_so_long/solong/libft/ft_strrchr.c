/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:40:59 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 21:27:10 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	size_t	length;
	char	ch;

	ch = (char)c;
	length = ft_strlen(src);
	src += length;
	while (length)
	{
		if (*src == ch)
			break ;
		src--;
		length--;
	}
	if (ch == 0 || *src == ch)
		return ((char *)src);
	else
		return (0);
}
