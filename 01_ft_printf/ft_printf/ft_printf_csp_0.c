/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:18:45 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/20 22:00:05 by jiychoi          ###   ########.fr       */
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

int			ft_print_p(t_format *fmt_conv, va_list param)
{
	unsigned long	absol;
	char			*pointer_to_print;
	char			*tmp;
	int				output;

	config_asterisk(fmt_conv, param);
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

	config_asterisk(fmt_conv, param);
	str_to_print = va_arg(param, char *);
	if (fmt_conv->precision < 0 && fmt_conv->precision > -2147483648)
		fmt_conv->precision = ft_strlen(str_to_print);
	output = print_ctrltwr_s(fmt_conv, str_to_print);
	return (output);
}

int			ft_print_c(t_format *fmt_conv, va_list param)
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

char		*check_if_percent(char *ptr_param)
{
	char *ptr_until;

	ptr_until = ft_strchr(ptr_param, '%');
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
