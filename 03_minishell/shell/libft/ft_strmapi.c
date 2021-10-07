/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:50:35 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/04 13:00:38 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	index;
	unsigned int	length;

	if (!s)
		return (0);
	length = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (0);
	index = 0;
	while (index < length)
	{
		ptr[index] = f(index, s[index]);
		index++;
	}
	ptr[index] = 0;
	return (ptr);
}
