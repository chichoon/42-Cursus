/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:37:33 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/17 16:47:00 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"


int		ctrltwr(char *param_start, char *param_end, int arg)
{
	if (*param_end = )
}

int		*get_varlist(const char *fmt)
{

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
		while (!if_available(*ptr_param, "cspdiuxX%") && *ptr_param)
			ptr_param++;
		if (!*ptr_param)
			return (output);
		output += ctrltwr(fmt, ptr_param, va_arg(param, int));
	}
}
