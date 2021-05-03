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

	ptr_backup = ptr;
	if (!ptr_backup)
		return (0);
	while (n > 0)
	{
		*ptr_backup++ = (unsigned char)value;
		n--;
	}
	return (ptr);
}
