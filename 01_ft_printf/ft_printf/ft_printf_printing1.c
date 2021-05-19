/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:37:36 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/19 14:45:43 by jiychoi          ###   ########.fr       */
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

int			print_if_zero(char *nb, int wtp, int ptp)
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

int			print_ctrltwr(t_format *fmt_conv, char *nb, int wtp, int ptp)
{
	if (fmt_conv->if_minus)
		return (print_if_minus(nb, wtp, ptp));
	else if (fmt_conv->if_zero && !fmt_conv->precision)
		return (print_if_zero(nb, wtp, ptp));
}

int			print_not_minus(t_format *fmt_conv, char *nb, int wtp, int ptp)
{
	int output;

	output = 0;
	if (fmt_conv->if_zero && !fmt_conv->precision)
	{
		while (wtp--)
		{
			output++;
			write(1, "0", 1);
		}
	}
	else
	{
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
	}
	return (output);
}

int			print_width(t_format *fmt_conv, char *nb, int wtp, int ptp)
{
	int output;

	output = 0;
	if (fmt_conv->if_minus)
	{
		return (print_if_minus(nb, wtp, ptp));
	}
	else
	{
		if (fmt_conv->if_zero && !fmt_conv->precision)
		{
			while (wtp--)
			{
				output++;
				write(1, "0", 1);
			}
		}
		else
		{
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
		}
	}
	return (output);
}

int			calc_width(t_format *fmt_conv, char *nb)
{
	int length;
	int width_to_print;
	int precis_to_print;

	length = ft_strlen(nb);
	if (fmt_conv->width <= fmt_conv->precision)
		width_to_print = 0;
	else
		width_to_print = fmt_conv->width - fmt_conv->precision;
	precis_to_print = fmt_conv->precision - length;
	if (fmt_conv->width < length)
	{
		width_to_print = 0;
	}
	if (fmt_conv->precision < length)
	{
		precis_to_print = 0;
	}
}
