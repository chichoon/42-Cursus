/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printing2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:01:34 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/19 22:49:12 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

int			print_if_minus(char *nb, int wtp, int ptp)
{
	int output;

	output = 0;
	while (ptp--)
	{
		output++;
		write(1, "0", 1);
	}
	output += ft_putstr(nb);
	while (wtp--)
	{
		output++;
		write(1, " ", 1);
	}
	return (output);
}

int			print_if_zero(char *nb, int wtp)
{
	int output;

	output = 0;
	while (wtp--)
	{
		output++;
		write(1, "0", 1);
	}
	output += ft_putstr(nb);
	return (output);
}

int			print_no_flags(char *nb, int wtp, int ptp)
{
	int output;

	output = 0;
	while (wtp--)
	{
		output++;
		write(1, " ", 1);
	}
	while (ptp--)
	{
		output++;
		write(1, "0", 1);
	}
	output += ft_putstr(nb);
	return (output);
}

int			print_if_minus_c(char c, int wtp)
{
	int output;

	output = 0;
	write(1, &c, 1);
	output++;
	while (wtp--)
	{
		output++;
		write(1, " ", 1);
	}
	return (output);
}

int			print_no_flags_c(char c, int wtp)
{
	int output;

	output = 0;
	while (wtp--)
	{
		output++;
		write(1, " ", 1);
	}
	write(1, &c, 1);
	output++;
	return (output);
}
