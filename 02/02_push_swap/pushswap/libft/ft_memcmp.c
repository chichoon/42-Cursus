/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:39:25 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 15:44:04 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_backup;
	unsigned char	*s2_backup;

	s1_backup = (unsigned char *)s1;
	s2_backup = (unsigned char *)s2;
	while (n)
	{
		if (*s1_backup != *s2_backup)
			return (*s1_backup - *s2_backup);
		s1_backup++;
		s2_backup++;
		n--;
	}
	return (0);
}
