/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:57:04 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/30 23:02:49 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

int	ft_atoi_pf(const char *str)
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

static int	ft_intlen(unsigned long n, unsigned int base_num)
{
	int	len;

	len = 1;
	while (n >= base_num)
	{
		len++;
		n /= base_num;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long absol, char *base)
{
	unsigned int	length;
	unsigned int	base_num;
	char			*ptr;

	base_num = ft_strlen_pf(base);
	length = ft_intlen(absol, base_num);
	ptr = (char *)malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (0);
	ptr[length] = 0;
	while (length)
	{
		ptr[--length] = base[absol % base_num];
		absol /= base_num;
	}
	return (ptr);
}

void	*free_and_return(void *ptr)
{
	free(ptr);
	return (0);
}
