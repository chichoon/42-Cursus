/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:50:38 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/19 14:26:58 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

int		ft_putstr_until(const char *src, const char *dst)
{
	int index;

	index = 0;
	while (src < dst && *src)
	{
		write(1, src++, 1);
		index++;
	}
	return (index);
}

int		ft_putstr(const char *src)
{
	int index;

	index = 0;
	while (*src)
	{
		write(1, src++, 1);
		index++;
	}
	return (index);
}
