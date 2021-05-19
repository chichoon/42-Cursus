/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:57:04 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/19 14:03:44 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

int					ft_atoi(const char *str)
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

static int			ft_intlen(unsigned long long n)
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

static unsigned int	find_int_divider(unsigned int nbr, unsigned int base_num)
{
	unsigned int len;

	len = 1;
	if (base_num == 2)
	{
		while (nbr >= base_num)
		{
			len *= base_num;
			nbr /= base_num;
		}
	}
	else
	{
		while (nbr > base_num)
		{
			len *= base_num;
			nbr /= base_num;
		}
	}
	return (len);
}

char				*ft_itoa_base(unsigned int absol, char *base)
{
	unsigned int	int_div;
	unsigned int	length;
	unsigned int	base_num;
	char			*ptr;

	int_div = find_int_divider(absol, base_num);
	base_num = ft_strlen(base);
	length = 0;
	while (int_div > 1)
	{
		length++;
		int_div /= base_num;
	}
	ptr = (char *)malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (0);
	length = 0;
	while (int_div > 1)
	{
		ptr[length++] = base[(absol / int_div) % base_num];
		absol = absol % int_div;
		int_div /= base_num;
	}
	ptr[length] = base[absol % base_num];
	return (ptr);
}

int					free_and_return(void *ptr)
{
	free(ptr);
	return (0);
}
