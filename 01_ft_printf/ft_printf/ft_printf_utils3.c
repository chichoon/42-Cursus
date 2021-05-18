/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:57:04 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/18 22:47:21 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				ft_atoi(const char *str)
{
	unsigned long long	absol;
	int					minus;

	minus = 1;
	absol = 0;
	while (*str <= '9' && *str >= '0')
		absol = absol * 10 + (*str++ - '0');
	if (absol >= 9223372036854775807 && minus == 1)
		return (-1);
	else if (absol >= 9223372036854775807 && minus == -1)
		return (0);
	return (minus * absol);
}

static int		ft_intlen(unsigned int n)
{
	int len;

	len = 1;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		intlen;
	char	*ptr;

	intlen = ft_intlen(n);
	ptr = (char *)malloc(sizeof(char) * (intlen + 1));
	if (!ptr)
		return (0);
	ptr[intlen] = 0;
	while (intlen)
	{
		ptr[--intlen] = '0' + (n % 10);
		n /= 10;
	}
	return (ptr);
}
