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

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	d_length;
	size_t	s_length;
	char	*src_backup;

	d_length = ft_strlen(dst);
	s_length = ft_strlen(src);
	src_backup = (char *)src;
	i = d_length;
	dst += i;
	while (i + 1 < n && *src_backup)
	{
		*dst++ = *src_backup++;
		i++;
	}
	if (d_length < n)
		*dst = 0;
	if (n < d_length)
		i = n + s_length;
	else
		i = d_length + s_length;
	return (i);
}
