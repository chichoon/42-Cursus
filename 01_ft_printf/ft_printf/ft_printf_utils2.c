/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:50:38 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/17 20:50:49 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

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

static char		*ft_itoa_neg(int n)
{
	unsigned int	absol;
	int				intlen;
	char			*ptr;

	absol = n * (-1);
	intlen = ft_intlen(absol) + 1;
	ptr = (char *)malloc(sizeof(char) * intlen + 1);
	if (!ptr)
		return (0);
	ptr[intlen] = 0;
	while (intlen > 1)
	{
		ptr[--intlen] = '0' + (absol % 10);
		absol /= 10;
	}
	ptr[0] = '-';
	return (ptr);
}

static char		*ft_itoa_pos(int n)
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

char			*ft_itoa(int n)
{
	if (n < 0)
		return (ft_itoa_neg(n));
	else
		return (ft_itoa_pos(n));
}
