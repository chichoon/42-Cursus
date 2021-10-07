/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:05:30 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/30 22:51:56 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_backup;
	unsigned char	*src_backup;

	if (!dst && !src && n)
		return (dst);
	if (dst > src)
	{
		dst_backup = (unsigned char *)dst + n - 1;
		src_backup = (unsigned char *)src + n - 1;
		while (n--)
			*dst_backup-- = *src_backup--;
	}
	else
	{
		dst_backup = (unsigned char *)dst;
		src_backup = (unsigned char *)src;
		while (n--)
			*dst_backup++ = *src_backup++;
	}
	return (dst);
}
