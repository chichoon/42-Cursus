/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_params_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:19:42 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/19 14:44:52 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"


int			ft_print_d(t_format *fmt_conv, va_list param)
{
	int				num;
	unsigned int	absol;
	int				output;
	char			*number_to_print;

	if (fmt_conv->if_asterisk_width)
		fmt_conv->width = va_arg(param, int);
	else if (fmt_conv->if_asterisk_precision)
		fmt_conv->width = va_arg(param, int);
	num = va_arg(param, int);
	output = 0;
	if (num < 0)
		absol = num * (-1);
	else
		absol = num;
	number_to_print = ft_itoa(absol);

}
