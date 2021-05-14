/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:37:33 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/14 20:19:25 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"


int		ctrltwr(char *param_start, char *param_end)
{

}

int		ft_printf(const char *fmt, ...)
{
	va_list	param;
	char	*convs;
	//char	*flags;
	char	*ptr_param;
	int		output;

	convs = "cspdiuxX%";
	//flags = "-0.";
	output = 0;
	if (!fmt)
		return (0);
	va_start(param, fmt);
	while (*fmt)
	{
		ptr_param = ft_strchr(fmt, '%');
		output += ft_write_until(fmt, ptr_param);
		fmt = ptr_param++;
		while (!if_available(*ptr_param, convs) && *ptr_param)
			ptr_param++;
		if (!*ptr_param)
			return (output);
		output += ctrltwr(fmt, ptr_param);
	}
}
