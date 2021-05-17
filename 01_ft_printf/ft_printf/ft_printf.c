/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:37:33 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/17 17:55:09 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

int		ctrltwr(char *param_start, char *param_end, va_list param)
{
	if (*param_end = 'c')
		return (ft_print_c(param_start, param_end, param));
	if (*param_end = 's')
		return (ft_print_s(param_start, param_end, param));
	if (*param_end = 'p')
		return (ft_print_p(param_start, param_end, param));
	if (*param_end = 'd')
		return (ft_print_d(param_start, param_end, param));
	if (*param_end = 'i')
		return (ft_print_i(param_start, param_end, param));
	if (*param_end = 'u')
		return (ft_print_u(param_start, param_end, param));
	if (*param_end = 'x')
		return (ft_print_lowx(param_start, param_end, param));
	if (*param_end = 'X')
		return (ft_print_lowx(param_start, param_end, param));
	if (*param_end = '%')
	{

	}
}

char	*get_convs_ptr(char *ptr_param)
{
	while (!if_available(*ptr_param, "cspdiuxX") && *ptr_param != '%'
			&& *ptr_param)
		ptr_param++;
	if (!*ptr_param || *ptr_param == '%')
		return (0);
	return (ptr_param);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	param;
	char	*ptr_param;
	int		output;

	output = 0;
	if (!fmt)
		return (0);
	va_start(param, fmt);
	while (*fmt)
	{
		ptr_param = ft_strchr(fmt, '%');
		output += ft_write_until(fmt, ptr_param);
		fmt = ptr_param++;
		if (*ptr_param == '%')
		{
			write(1, "%", 1);
			output++;
		}
		if (get_convs_ptr(ptr_param))
		{
			ptr_param = get_convs_ptr(ptr_param);
			output += ctrltwr(fmt, ptr_param, param);
		}
		fmt = ptr_param + 1;
	}
}

int		main(void)
{
	printf("hello %d %d\n", 123, 123);
	ft_printf("hello %d %d\n", 123, 123);
}
