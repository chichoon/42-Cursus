/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:37:33 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/21 12:31:10 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static int	ctrl_twr(t_format *fmt_conv, va_list param)
{
	int output;

	output = 0;
	if (fmt_conv->type == 'c' || fmt_conv->type == '%')
		output = ft_print_c(fmt_conv, param);
	if (fmt_conv->type == 's')
		output = ft_print_s(fmt_conv, param);
	if (fmt_conv->type == 'p')
		output = ft_print_p(fmt_conv, param);
	if (fmt_conv->type == 'd' || fmt_conv->type == 'i')
		output = ft_print_d(fmt_conv, param);
	if (fmt_conv->type == 'u')
		output = ft_print_u(fmt_conv, param);
	if (fmt_conv->type == 'x')
		output = ft_print_x(fmt_conv, param, 1);
	if (fmt_conv->type == 'X')
		output = ft_print_x(fmt_conv, param, 0);
	free(fmt_conv);
	return (output);
}

static char	*get_convs_ptr(char *ptr_param)
{
	while (!if_available(*ptr_param, "cspdiuxX") && *ptr_param != '%'
			&& *ptr_param)
		ptr_param++;
	if (!*ptr_param || *ptr_param == '%')
		return (0);
	return (ptr_param);
}

static int	ft_printf_main(char *fmt, va_list param)
{
	t_format	*fmt_conv;
	char		*fmt_until;
	int			output;

	output = 0;
	while (*fmt)
	{
		fmt_until = ft_strchr_pf(fmt, '%');
		if (!fmt_until)
			return (output + ft_putstr_pf(fmt));
		output += ft_putstr_until(fmt, fmt_until);
		fmt = fmt_until++;
		if (check_if_percent(fmt_until) || get_convs_ptr(fmt_until))
		{
			if (check_if_percent(fmt_until))
				fmt_until = check_if_percent(fmt_until);
			else if (get_convs_ptr(fmt_until))
				fmt_until = get_convs_ptr(fmt_until);
			fmt_conv = def_format(fmt, fmt_until);
			if (fmt_conv)
				output += ctrl_twr(fmt_conv, param);
		}
		fmt = fmt_until + 1;
	}
	return (output);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	param;
	char	*fmt_start;
	int		output;

	if (!fmt)
		return (0);
	fmt_start = (char *)fmt;
	va_start(param, fmt);
	output = ft_printf_main(fmt_start, param);
	va_end(param);
	return (output);
}
