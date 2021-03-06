/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:53:40 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/30 22:51:11 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_backup;
	unsigned char	*src_backup;

	dst_backup = (unsigned char *)dst;
	src_backup = (unsigned char *)src;
	if (!dst && !src && n)
		return (dst);
	while (n)
	{
		*dst_backup++ = *src_backup++;
		n--;
	}
	return (dst);
}
