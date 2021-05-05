/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:59:08 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/04 12:48:18 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(unsigned int n)
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

char	*ft_itoa_neg(int n)
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

char	*ft_itoa_pos(int n)
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

char	*ft_itoa(int n)
{
	if (n < 0)
		return (ft_itoa_neg(n));
	else
		return (ft_itoa_pos(n));
}
