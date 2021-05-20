/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:59:53 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/20 21:55:45 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static int	calc_width(t_format *fmt_conv, int length)
{
	if (fmt_conv->width < 0)
		return (0);
	if (length > fmt_conv->precision)
	{
		if (fmt_conv->precision == -2147483648 && fmt_conv->if_dot)
			return (fmt_conv->width);
		if (fmt_conv->precision == -2147483648 && !fmt_conv->if_dot)
			if (fmt_conv->width > length)
				return (fmt_conv->width - length);
		if (fmt_conv->precision > 0 && fmt_conv->width > fmt_conv->precision)
			return (fmt_conv->width - fmt_conv->precision);
		return (0);
	}
	else
	{
		if (fmt_conv->width > length)
			return (fmt_conv->width - length);
		return (0);
	}
}

static int	calc_length(t_format *fmt_conv, char *str)
{
	int length;

	length = ft_strlen(str);
	if (fmt_conv->precision == -2147483648 && fmt_conv->if_dot)
		return (0);
	if (fmt_conv->precision == -2147483648 && !fmt_conv->if_dot)
		return (length);
	if (length > fmt_conv->precision)
		return (fmt_conv->precision);
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
	else if (fmt_conv->if_zero && fmt_conv->type == '%')
		return (print_if_zero_c(c, wtp));
	else
		return (print_no_flags_c(c, wtp));
}

int			print_ctrltwr_s(t_format *fmt_conv, char *str)
{
	int wtp;
	int length;

	length = calc_length(fmt_conv, str);
	wtp = calc_width(fmt_conv, length);
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
