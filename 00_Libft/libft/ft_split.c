/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:07:49 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/14 13:36:49 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_wc(char *str, char c)
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

static int	ft_get_wl(char *str, char c)
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

char		*ft_strndup(char *str, int length)
{
	char	*ptr;
	char	*ptr_backup;

	ptr = (char *)malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (0);
	ptr_backup = ptr;
	while (length--)
		*ptr++ = *str++;
	*ptr = 0;
	return (ptr_backup);
}

static char	**ft_free_char2d(char **arr)
{
	int index;

	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
	return (0);
}

char		**ft_split(char const *s, char c)
{
	int		wordlength;
	int		wordcount;
	char	**array;
	int		index;

	if (!s)
		return (0);
	wordcount = ft_get_wc((char *)s, c);
	array = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!array)
		return (0);
	index = -1;
	while (++index < wordcount)
	{
		while (*s == c)
			s++;
		wordlength = ft_get_wl((char *)s, c);
		array[index] = ft_strndup((char *)s, wordlength);
		if (!array[index])
			return (ft_free_char2d(array));
		s += wordlength;
	}
	array[index] = 0;
	return (array);
}
