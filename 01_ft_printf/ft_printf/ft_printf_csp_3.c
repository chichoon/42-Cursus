/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 00:56:42 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/21 01:22:32 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

int			print_if_zero_s(char *str, int wtp, int length)
{
	int output;

	output = 0;
	while (wtp--)
	{
		output++;
		write(1, "0", 1);
	}
	output += ft_putstr_until(str, str + length);
	return (output);
}

int			print_no_flags_p(char *nb, int wtp, int ptp)
{
	int output;

	output = 2;
	while (wtp-- > 0)
	{
		output++;
		write(1, " ", 1);
	}
	write(1, "0x", 2);
	while (ptp-- > 0)
	{
		output++;
		write(1, "0", 1);
	}
	output += ft_putstr(nb);
	return (output);
}

int			print_if_minus_p(char *nb, int wtp, int ptp)
{
	int output;

	output = 2;
	write(1, "0x", 2);
	while (ptp-- > 0)
	{
		output++;
		write(1, "0", 1);
	}
	output += ft_putstr(nb);
	while (wtp-- > 0)
	{
		output++;
		write(1, " ", 1);
	}
	return (output);
}
