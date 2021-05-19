/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:37:33 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/19 16:26:01 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static int	ctrltwr(t_format *fmt_conv, va_list param)
{
	int output;

	output = 0;
	if (fmt_conv->type = 'c')
		output = ft_print_c(fmt_conv, param);
	if (fmt_conv->type = 's')
		output = ft_print_s(fmt_conv, param);
	if (fmt_conv->type = 'p')
		output = ft_print_p(fmt_conv, param);
	if (fmt_conv->type = 'd')
		output = ft_print_d(fmt_conv, param);
	if (fmt_conv->type = 'i')
		output = ft_print_i(fmt_conv, param);
	if (fmt_conv->type = 'u')
		output = ft_print_u(fmt_conv, param);
	if (fmt_conv->type = 'x')
		output = ft_print_lowx(fmt_conv, param);
	if (fmt_conv->type = 'X')
		output = ft_print_uppx(fmt_conv, param);
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

int			ft_printf_main(const char *fmt, va_list param)
{
	t_format	*fmt_conv;
	char		*fmt_until;
	int			output;

	output = 0;
	while (*fmt)
	{
		fmt_until = ft_strchr(fmt, '%');
		output += ft_putstr_until(fmt, fmt_until);
		fmt = fmt_until++;
		if (*fmt_until == '%')
		{
			write(1, "%", 1);
			output++;
		}
		else if (get_convs_ptr(fmt_until))
		{
			fmt_until = get_convs_ptr(fmt_until);
			fmt_conv = def_format(fmt, fmt_until, param);
			if (fmt_conv)
				output += ctrltwr(fmt_conv, param);
		}
		fmt = fmt_until + 1;
	}
	return (output);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	param;

	if (!fmt)
		return (0);
	va_start(param, fmt);
	return (ft_printf_main(fmt, param));
}

int		main(void)
{
	printf("hello %d %d\n", 123, 123);
	ft_printf("hello %d %d\n", 123, 123);
}
