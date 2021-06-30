/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:18:45 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/30 22:59:11 by jiychoi          ###   ########.fr       */
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

int	ft_print_p(t_format *fmt_conv, va_list param)
{
	unsigned long	absol;
	char			*pointer_to_print;
	int				output;

	config_asterisk(fmt_conv, param);
	absol = (unsigned long)va_arg(param, void *);
	if (absol == 0 && fmt_conv->if_dot
		&& (fmt_conv->precision > 0 || fmt_conv->precision == -2147483648))
		pointer_to_print = ft_strjoin_pf("", "");
	else
		pointer_to_print = ft_itoa_base(absol, "0123456789abcdef");
	output = print_ctrltwr_p(fmt_conv, pointer_to_print);
	free(pointer_to_print);
	return (output);
}

int	ft_print_s(t_format *fmt_conv, va_list param)
{
	char	*str_to_print;
	int		if_null;
	int		output;

	config_asterisk(fmt_conv, param);
	str_to_print = va_arg(param, char *);
	if_null = 0;
	if (!str_to_print)
	{
		str_to_print = ft_strjoin_pf("(null)", "");
		if_null = 1;
	}
	if (fmt_conv->precision < 0 && fmt_conv->precision > -2147483648)
		fmt_conv->precision = ft_strlen_pf(str_to_print);
	output = print_ctrltwr_s(fmt_conv, str_to_print);
	if (if_null)
		free(str_to_print);
	return (output);
}

int	ft_print_c(t_format *fmt_conv, va_list param)
{
	char	char_to_print;
	int		output;

	config_asterisk(fmt_conv, param);
	if (fmt_conv->type == 'c')
		char_to_print = (char)va_arg(param, int);
	else
		char_to_print = '%';
	output = print_ctrltwr_c(fmt_conv, char_to_print);
	return (output);
}

char	*check_if_percent(char *ptr_param)
{
	char	*ptr_until;

	ptr_until = ft_strchr_pf(ptr_param, '%');
	if (!ptr_until)
		return (0);
	while (ptr_param < ptr_until)
	{
		if (!if_available(*ptr_param, "0-.*123456789"))
			return (0);
		ptr_param++;
	}
	return (ptr_until);
}
