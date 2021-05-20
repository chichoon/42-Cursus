/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_params_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:19:42 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/19 22:19:06 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

int			ft_print_d(t_format *fmt_conv, va_list param)
{
	int				num;
	unsigned int	absol;
	char			*number_to_print;
	int				output;

	if (fmt_conv->if_asterisk_width)
		fmt_conv->width = va_arg(param, int);
	else if (fmt_conv->if_asterisk_precision)
		fmt_conv->width = va_arg(param, int);
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
	number_to_print = ft_itoa_base(absol, "0123456789");
	output = print_ctrltwr(fmt_conv, number_to_print, num);
	free(number_to_print);
	return (output);
}

int			ft_print_u(t_format *fmt_conv, va_list param)
{
	unsigned int	absol;
	char			*number_to_print;
	int				output;

	if (fmt_conv->if_asterisk_width)
		fmt_conv->width = va_arg(param, int);
	else if (fmt_conv->if_asterisk_precision)
		fmt_conv->width = va_arg(param, int);
	absol = va_arg(param, unsigned int);
	number_to_print = ft_itoa_base(absol, "0123456789");
	output = print_ctrltwr(fmt_conv, number_to_print, 1);
	free(number_to_print);
	return (output);
}

int			ft_print_x(t_format *fmt_conv, va_list param, int if_low)
{
	unsigned int	absol;
	char			*number_to_print;
	int				output;

	if (fmt_conv->if_asterisk_width)
		fmt_conv->width = va_arg(param, int);
	else if (fmt_conv->if_asterisk_precision)
		fmt_conv->width = va_arg(param, int);
	absol = va_arg(param, unsigned int);
	if (if_low)
		number_to_print = ft_itoa_base(absol, "0123456789abcdef");
	else
		number_to_print = ft_itoa_base(absol, "0123456789ABCDEF");
	output = print_ctrltwr(fmt_conv, number_to_print, 1);
	free(number_to_print);
	return (output);
}
