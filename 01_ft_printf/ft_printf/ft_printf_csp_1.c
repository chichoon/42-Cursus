/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:59:53 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/20 14:18:12 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

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

	length = ft_strlen(str);
	if (length > fmt_conv->precision)
	{
		length = fmt_conv->precision;
		if (fmt_conv->width > fmt_conv->precision)
			wtp = fmt_conv->width - fmt_conv->precision;
		else
			wtp = 0;
	}
	else
	{
		if (fmt_conv->width > length)
			wtp = fmt_conv->width - length;
		else
			wtp = 0;
	}
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
