/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:09:44 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/16 21:57:23 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

char	*ft_strstr(char *str, char *to_find)
{
	char	*tmp;
	char	*tmp_find;

	if (!*to_find)
		return (str);
	while (1)
	{
		tmp_find = to_find;
		while (*str != *tmp_find)
		{
			if (!*str++)
				return (0);
		}
		tmp = str;
		while (*tmp_find)
		{
			if (*str != *tmp_find)
				break ;
			str++;
			tmp_find++;
		}
		if (!*tmp_find)
			break ;
	}
	return (tmp);
}

char	**ft_free_char2d(char **arr)
{
	int index;

	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
	return (0);
}

int		ft_if_available(char s, char *arr)
{
	while (*arr)
	{
		if (*arr == s)
			return (1);
		arr++;
	}
	return (0);
}
