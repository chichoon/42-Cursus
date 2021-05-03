/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:41:19 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 14:35:40 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t n)
{
	unsigned char		*ptr_backup;
	unsigned long long	num;

	ptr_backup = ptr;
	num = (unsigned long long)n;
	if (!ptr_backup)
		return (0);
	while (num > 0)
	{
		*ptr_backup++ = (unsigned char)value;
		num--;
	}
	return (ptr);
}
