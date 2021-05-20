/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_params_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:18:45 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/20 13:16:15 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

int			ft_print_p(t_format *fmt_conv, va_list param)
{
	unsigned long	absol;
	char			*number_to_print;
	char			*tmp;
	int				output;

	if (fmt_conv->if_asterisk_width)
		fmt_conv->width = va_arg(param, int);
	absol = (unsigned long)va_arg(param, void *);
	tmp = ft_itoa_base(absol, "0123456789abcdef");
	number_to_print = ft_strjoin("0x", tmp);
	free(tmp);
	output = print_ctrltwr(fmt_conv, number_to_print, 1);
	free(number_to_print);
	return (output);
}

int			ft_print_s(t_format *fmt_conv, va_list param)
{
	char			*number_to_print;
	int				output;

	if (fmt_conv->if_asterisk_width)
		fmt_conv->width = va_arg(param, int);
	number_to_print = va_arg(param, char *);
	output = print_ctrltwr_sp(fmt_conv, number_to_print);
	return (output);
}

int			ft_print_c(t_format *fmt_conv, va_list param)
{
	char			number_to_print;
	int				output;

	if (fmt_conv->if_asterisk_width)
		fmt_conv->width = va_arg(param, int);
	number_to_print = (char)va_arg(param, int);
	output = print_ctrltwr_c(fmt_conv, number_to_print);
	return (output);
}
