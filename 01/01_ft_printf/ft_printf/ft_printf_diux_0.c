/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diux_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:19:42 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/21 02:06:46 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static void	config_asterisk(t_format *fmt_conv, va_list param)
{
	if (fmt_conv->if_asterisk_width)
	{
		fmt_conv->width = va_arg(param, int);
		if (fmt_conv->width < 0)
		{
			fmt_conv->width *= -1;
			fmt_conv->if_minus = 1;
		}
	}
	if (fmt_conv->if_asterisk_precision)
		fmt_conv->precision = va_arg(param, int);
}

int			ft_print_d(t_format *fmt_conv, va_list param)
{
	int				num;
	unsigned int	absol;
	char			*number_to_print;
	int				output;

	config_asterisk(fmt_conv, param);
	num = va_arg(param, int);
	if (num < 0)
	{
		absol = num * (-1);
		num = 0;
	}
	else
	{
		absol = num;
		num = 1;
	}
	if (absol == 0 && fmt_conv->if_dot
		&& (fmt_conv->precision >= 0 || fmt_conv->precision == -2147483648))
		number_to_print = ft_strjoin_pf("", "");
	else
		number_to_print = ft_itoa_base(absol, "0123456789");
	output = print_ctrltwr_diux(fmt_conv, number_to_print, num);
	free(number_to_print);
	return (output);
}

int			ft_print_u(t_format *fmt_conv, va_list param)
{
	unsigned int	absol;
	char			*number_to_print;
	int				output;

	config_asterisk(fmt_conv, param);
	absol = va_arg(param, unsigned int);
	if (absol == 0 && fmt_conv->if_dot
		&& (fmt_conv->precision >= 0 || fmt_conv->precision == -2147483648))
		number_to_print = ft_strjoin_pf("", "");
	else
		number_to_print = ft_itoa_base(absol, "0123456789");
	output = print_ctrltwr_diux(fmt_conv, number_to_print, 1);
	free(number_to_print);
	return (output);
}

int			ft_print_x(t_format *fmt_conv, va_list param, int if_low)
{
	unsigned int	absol;
	char			*number_to_print;
	int				output;

	config_asterisk(fmt_conv, param);
	absol = va_arg(param, unsigned int);
	if (absol == 0 && fmt_conv->if_dot
		&& (fmt_conv->precision >= 0 || fmt_conv->precision == -2147483648))
		number_to_print = ft_strjoin_pf("", "");
	else
	{
		if (if_low)
			number_to_print = ft_itoa_base(absol, "0123456789abcdef");
		else
			number_to_print = ft_itoa_base(absol, "0123456789ABCDEF");
	}
	output = print_ctrltwr_diux(fmt_conv, number_to_print, 1);
	free(number_to_print);
	return (output);
}
