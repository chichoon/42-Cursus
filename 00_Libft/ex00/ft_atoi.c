/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:16:48 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/03 20:02:12 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char str)
{
	if (str == ' ' || (str >= 9 && str <= 13))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	absol;
	int				minus;

	minus = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
		absol = absol * 10 + (*str++ - '0');
	return (minus * absol);
}
