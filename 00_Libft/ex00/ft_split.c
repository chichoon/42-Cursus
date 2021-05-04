/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:07:49 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/04 11:57:28 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_wc(char *str, char c)
{
	int index;

	index = 0;
	while (*str)
	{
		if (*str != c)
			if (*(str + 1) == c || !*(str + 1))
				index++;
		str++;
	}
	return (index);
}

int		ft_get_wl(char *str, char c)
{
	int length;

	length = 0;
	while (*str && *str != c)
	{
		length++;
		str++;
	}
	return (length);
}

char	*ft_strndup(char *str, int length)
{
	char	*ptr;
	char	*ptr_backup;

	ptr = (char *)malloc(sizeof(char) * length + 1);
	if (!ptr)
		return (0);
	ptr_backup = ptr;
	while (length--)
		*ptr++ = *str++;
	*ptr = 0;
	return (ptr_backup);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	int		wordlength;
	int		wordcount;
	char	**array;
	int		index;

	str = (char *)s;
	wordcount = ft_get_wc(str, c);
	array = (char **)malloc(sizeof(char *) * wordcount + 1);
	if (!array)
		return (0);
	index = 0;
	while (index < wordcount)
	{
		while (*str == c)
			str++;
		wordlength = ft_get_wl(str, c);
		array[index++] = ft_strndup(str, wordlength);
		str += wordlength;
	}
	array[index] = 0;
	return (array);
}
