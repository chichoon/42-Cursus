/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:59:53 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/20 14:45:25 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static int	calc_width(t_format *fmt_conv, char *str)
{
	int length;
	int width_to_print;

	length = ft_strlen(str);
	if (fmt_conv->width < 0)
		return (0);
	if (length > fmt_conv->precision)
	{
		if (fmt_conv->width > fmt_conv->precision)
			width_to_print = fmt_conv->width - fmt_conv->precision;
		else
			width_to_print = 0;
	}
	else
	{
		if (fmt_conv->width > length)
			width_to_print = fmt_conv->width - length;
		else
			width_to_print = 0;
	}
	return (width_to_print);
}

static int	calc_length(t_format *fmt_conv, char *str)
{
	int length;

	length = ft_strlen(str);
	if (fmt_conv->precision < 0)
		return (length);
	if (length > fmt_conv->precision)
		length = fmt_conv->precision;
	return (length);
}

int			print_ctrltwr_c(t_format *fmt_conv, char c)
{
	int		wtp;
	int		output;

	if (fmt_conv->width > 1)
		wtp = fmt_conv->width - 1;
	else
		wtp = 0;
	output = 0;
	if (fmt_conv->if_minus)
		return (print_if_minus_c(c, wtp));
	else
		return (print_no_flags_c(c, wtp));
}

int			print_ctrltwr_s(t_format *fmt_conv, char *str)
{
	int wtp;
	int length;

	length = calc_length(fmt_conv, str);
	wtp = calc_width(fmt_conv, str);
	if (fmt_conv->if_minus)
		return (print_if_minus_s(str, wtp, length));
	else
		return (print_no_flags_s(str, wtp, length));
}

int			print_ctrltwr_p(t_format *fmt_conv, char *str)
{
	int		wtp;
	int		ptp;
	int		length;

	length = ft_strlen(str);
	if (fmt_conv->width > length)
		wtp = fmt_conv->width - length;
	else
		wtp = 0;
	ptp = 0;
	if (fmt_conv->if_minus)
		return (print_if_minus(str, wtp, ptp));
	else
		return (print_no_flags(str, wtp, ptp));
}
