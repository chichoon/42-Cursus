/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:01:02 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 15:12:18 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n)
{
	unsigned char *restrict	d_backup;
	unsigned char *restrict s_backup;
	unsigned char			uc;

	d_backup = (unsigned char *restrict)d;
	s_backup = (unsigned char *restrict)s;
	uc = (unsigned char)c;
	while (n)
	{
		if (*s_backup == c)
			return (d);
		*d_backup++ = *s_backup++;
	}
	return (0);
}
