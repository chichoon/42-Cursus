/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:15:34 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/30 22:52:38 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char s1, char const *set)
{
	while (*set)
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*start;
	char			*end;
	unsigned int	range;
	char			*ptr;

	if (!s1 || !set)
		return (0);
	start = (char *)s1;
	end = (char *)s1 + ft_strlen(s1);
	while (ft_is_in_set(*start, set))
		start++;
	while (ft_is_in_set(*(end - 1), set) && start < end)
		end--;
	range = end - start;
	ptr = (char *)malloc(sizeof(char) * (range + 1));
	if (!ptr)
		return (0);
	ft_memcpy(ptr, start, range);
	ptr += range;
	*ptr = 0;
	return (ptr - range);
}
