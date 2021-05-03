/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:17:15 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 15:38:19 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char *src_backup;

	src_backup = (unsigned char *)src;
	while (n)
	{
		if (*src_backup == (unsigned char)c)
			return (src_backup);
		n--;
	}
	return (0);
}
