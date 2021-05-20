/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_params_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:18:45 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/20 13:49:32 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

int			ft_print_p(t_format *fmt_conv, va_list param)
{
	unsigned long	absol;
	char			*pointer_to_print;
	char			*tmp;
	int				output;

	if (fmt_conv->if_asterisk_width)
		fmt_conv->width = va_arg(param, int);
	absol = (unsigned long)va_arg(param, void *);
	tmp = ft_itoa_base(absol, "0123456789abcdef");
	pointer_to_print = ft_strjoin("0x", tmp);
	free(tmp);
	output = print_ctrltwr_p(fmt_conv, pointer_to_print);
	free(pointer_to_print);
	return (output);
}

int			ft_print_s(t_format *fmt_conv, va_list param)
{
	char	*str_to_print;
	int		output;

	if (fmt_conv->if_asterisk_width)
		fmt_conv->width = va_arg(param, int);
	str_to_print = va_arg(param, char *);
	output = print_ctrltwr_s(fmt_conv, str_to_print);
	return (output);
}

int			ft_print_c(t_format *fmt_conv, va_list param)
{
	char	char_to_print;
	int		output;

	if (fmt_conv->if_asterisk_width)
		fmt_conv->width = va_arg(param, int);
	char_to_print = (char)va_arg(param, int);
	output = print_ctrltwr_c(fmt_conv, char_to_print);
	return (output);
}
