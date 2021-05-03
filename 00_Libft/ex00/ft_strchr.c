/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:38:58 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 20:31:43 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	while (*src)
	{
		if (*src == c)
			break ;
		src++;
	}
	if (c == 0 || *src == c)
		return ((char *)src);
	else
		return (0);
}
