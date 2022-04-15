/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrlength.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:53:55 by jiychoi           #+#    #+#             */
/*   Updated: 2022/02/17 14:58:41 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_length_char2d(char **arr) {
	int	length;

	length = 0;
	while (arr[length])
		length++;
	return (length);
}

int	main(void)
{
	char *arr[3] = {"aa", "aa", 0};
	printf("%d\n", ft_length_char2d(arr));
}
