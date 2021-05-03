/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:16:02 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 18:42:22 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *restrict src, size_t n)
{
	size_t			i;
	size_t			d_length;
	char			*dst_backup;
	char			*src_backup;

	i = 0;
	dst_backup = dst;
	src_backup = (char *)src;
	d_length = ft_strlen(dst);
	i = d_length;
	dst_backup += i;
	while (i + 1 < n && *src_backup)
	{
		*dst_backup++ = *src_backup++;
		i++;
	}
	*dst_backup = 0;
	if (n < d_length)
		i = n + ft_strlen(src);
	else
		i = d_length + ft_strlen(src);
	return (i);
}
