/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printing3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:01:34 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/19 20:29:23 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

int			print_neg_if_minus(char *nb, int wtp, int ptp)
{
	int output;

	output = 0;
	while (ptp--)
	{
		output++;
		write(1, "0", 1);
	}
	write(1, "-", 1);
	wtp--;
	output += (ft_putstr(nb) + 1);
	while (wtp--)
	{
		output++;
		write(1, " ", 1);
	}
	return (output);
}

int			print_neg_if_zero(char *nb, int wtp)
{
	int output;

	output = 1;
	write(1, "-", 1);
	wtp--;
	while (wtp--)
	{
		output++;
		write(1, "0", 1);
	}
	output += ft_putstr(nb);
	return (output);
}

int			print_neg_no_flags(char *nb, int wtp, int ptp)
{
	int output;

	output = 0;
	wtp--;
	while (wtp-- > 0)
	{
		output++;
		write(1, " ", 1);
	}
	write(1, "-", 1);
	output++;
	while (ptp--)
	{
		output++;
		write(1, "0", 1);
	}
	output += ft_putstr(nb);
	return (output);
}
