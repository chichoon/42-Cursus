/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:02:57 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/30 22:59:52 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

int	print_if_minus_c(char c, int wtp)
{
	int	output;

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

int	print_if_zero_c(char c, int wtp)
{
	int	output;

	output = 0;
	while (wtp--)
	{
		output++;
		write(1, "0", 1);
	}
	write(1, &c, 1);
	output++;
	return (output);
}

int	print_no_flags_c(char c, int wtp)
{
	int	output;

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

int	print_if_minus_s(char *str, int wtp, int length)
{
	int	output;

	output = ft_putstr_until(str, str + length);
	while (wtp--)
	{
		output++;
		write(1, " ", 1);
	}
	return (output);
}

int	print_no_flags_s(char *str, int wtp, int length)
{
	int	output;

	output = 0;
	while (wtp--)
	{
		output++;
		write(1, " ", 1);
	}
	output += ft_putstr_until(str, str + length);
	return (output);
}
