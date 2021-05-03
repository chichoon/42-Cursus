/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:38:12 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 21:45:07 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*ptr_backup;

	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (0);
	ptr_backup = ptr;
	s += start;
	while (*s && len)
	{
		*ptr++ = *s++;
		len--;
	}
	return (ptr_backup);
}
