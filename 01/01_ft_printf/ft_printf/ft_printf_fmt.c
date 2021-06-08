/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:34:31 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/21 12:31:26 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static void		init_format(t_format *fmt)
{
	fmt->type = 0;
	fmt->width = -2147483648;
	fmt->precision = -2147483648;
	fmt->if_zero = 0;
	fmt->if_dot = 0;
	fmt->if_minus = 0;
	fmt->if_asterisk_precision = 0;
	fmt->if_asterisk_width = 0;
}

static void		put_length(char *str, t_format *fmt_new)
{
	if (!fmt_new->if_dot)
		fmt_new->width = ft_atoi_pf(str);
	else
		fmt_new->precision = ft_atoi_pf(str);
}

static int		put_flags(char str, t_format *fmt_new)
{
	if (if_available(str, "0-*."))
	{
		if (str == '0' && !fmt_new->if_dot && !fmt_new->if_zero)
			fmt_new->if_zero = 1;
		if (str == '-' && !fmt_new->if_dot)
			fmt_new->if_minus = 1;
		if (str == '*' && !fmt_new->if_dot)
			fmt_new->if_asterisk_width = 1;
		if (str == '*' && fmt_new->if_dot)
			fmt_new->if_asterisk_precision = 1;
		if (str == '.')
			fmt_new->if_dot = 1;
		return (1);
	}
	return (0);
}

static int		if_exceptions(char str, t_format *fmt_new)
{
	if (!if_available(str, "%0-.*123456789cspdiuxX"))
		return (1);
	if (fmt_new->if_dot && !if_available(str, "0123456789"))
		return (1);
	if (fmt_new->if_asterisk_width && !fmt_new->if_dot)
		if (str <= '9' && str >= '0')
			return (1);
	if (fmt_new->if_asterisk_precision && fmt_new->if_dot)
		if (str <= '9' && str >= '0')
			return (1);
	if (fmt_new->precision >= 0 && !if_available(str, "cspdiuxX"))
		return (1);
	if (fmt_new->if_asterisk_precision && fmt_new->if_asterisk_width)
		return (1);
	return (0);
}

t_format		*def_format(char *param_start, char *param_end)
{
	t_format	*fmt_new;

	fmt_new = (t_format *)malloc(sizeof(t_format));
	if (!fmt_new)
		return (0);
	init_format(fmt_new);
	param_start++;
	while (param_start < param_end)
	{
		if (put_flags(*param_start, fmt_new))
			param_start++;
		else if (*param_start <= '9' && *param_start >= '0')
		{
			put_length(param_start, fmt_new);
			while (*param_start <= '9' && *param_start >= '0')
				param_start++;
		}
		else if (if_exceptions(*param_start, fmt_new))
			return (free_and_return(fmt_new));
	}
	fmt_new->type = *param_end;
	return (fmt_new);
}
