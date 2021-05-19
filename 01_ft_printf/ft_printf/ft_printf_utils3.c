/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:15:05 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/19 22:16:31 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst_backup;
	unsigned char *src_backup;

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

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*ptr_backup;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!ptr)
		return (0);
	ptr_backup = ptr;
	ft_memcpy(ptr, s1, len_s1);
	ptr += len_s1;
	ft_memcpy(ptr, s2, len_s2);
	ptr += len_s2;
	*ptr = 0;
	return (ptr_backup);
}
