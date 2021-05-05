/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:01:02 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 20:11:12 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*dst_backup;
	unsigned char			*src_backup;
	unsigned char			uc;

	dst_backup = (unsigned char *)dst;
	src_backup = (unsigned char *)src;
	uc = (unsigned char)c;
	while (n)
	{
		*dst_backup = *src_backup;
		if (*src_backup == uc)
			return (++dst_backup);
		dst_backup++;
		src_backup++;
		n--;
	}
	return (0);
}
