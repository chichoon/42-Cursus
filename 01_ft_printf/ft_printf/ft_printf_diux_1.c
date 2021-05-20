/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diux_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:57:23 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/20 14:01:38 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static int	calc_width(t_format *fmt_conv, char *nb)
{
	int length;
	int width_to_print;

	length = ft_strlen(nb);
	if (fmt_conv->width <= fmt_conv->precision)
		width_to_print = 0;
	else if (fmt_conv->precision < length)
		width_to_print = fmt_conv->width - length;
	else
		width_to_print = fmt_conv->width - fmt_conv->precision;
	if (fmt_conv->width < length)
		width_to_print = 0;
	return (width_to_print);
}

static int	calc_precis(t_format *fmt_conv, char *nb)
{
	int length;
	int precis_to_print;

	length = ft_strlen(nb);
	precis_to_print = fmt_conv->precision - length;
	if (fmt_conv->precision < length)
		precis_to_print = 0;
	return (precis_to_print);
}

int			print_ctrltwr_diux(t_format *fmt_conv, char *nb, int if_pos)
{
	int		wtp;
	int		ptp;

	wtp = calc_width(fmt_conv, nb);
	ptp = calc_precis(fmt_conv, nb);
	if (if_pos)
	{
		if (fmt_conv->if_minus)
			return (print_if_minus(nb, wtp, ptp));
		else if (fmt_conv->if_zero && !fmt_conv->if_dot)
			return (print_if_zero(nb, wtp));
		return (print_no_flags(nb, wtp, ptp));
	}
	else
	{
		if (fmt_conv->if_minus)
			return (print_neg_if_minus(nb, wtp, ptp));
		else if (fmt_conv->if_zero && !fmt_conv->if_dot)
			return (print_neg_if_zero(nb, wtp));
		return (print_neg_no_flags(nb, wtp, ptp));
	}
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
