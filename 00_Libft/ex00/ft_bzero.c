/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:14:56 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 14:47:31 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*ptr_backup;

	ptr_backup = ptr;
	if (!ptr)
		return ;
	while (n > 0)
	{
		*ptr_backup++ = 0;
		n--;
	}
}
