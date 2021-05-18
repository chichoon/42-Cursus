/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:34:31 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/18 23:12:13 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static void		init_format(t_format *fmt)
{
	fmt->type = 0;
	fmt->width = 0;
	fmt->precision = 0;
	fmt->if_zero = 0;
	fmt->if_minus = 0;
	fmt->if_plus = 0;
	fmt->if_space = 0;
	fmt->if_hash = 0;
}

static void		put_length(char *str, t_format *fmt_new)
{
	if (*str < '9' && *str > '0' && fmt_new->if_dot == 0)
	{
		fmt_new->width = ft_atoi(str);
		while (*str < '9' && *str > '0')
			str++;
	}
	if (*str == '.')
		fmt_new->if_dot = 1;
	if (*str < '9' && *str > '0' && fmt_new->if_dot == 1)
	{
		fmt_new->precision = ft_atoi(str);
		while (*str < '9' && str > '0')
			str++;
	}
}

static void		put_format(char str, t_format *fmt_new)
{
	if (str == '0' && fmt_new->if_dot == 0 && fmt_new->if_zero == 0)
		fmt_new->if_zero = 1;
	if (str == '-' && fmt_new->if_dot == 0)
		fmt_new->if_minus = 1;
	if (str == '+' && fmt_new->if_dot == 0)
		fmt_new->if_plus = 1;
	if (str == ' ' && fmt_new->if_dot == 0)
		fmt_new->if_space = 1;
	if (str == '#' && fmt_new->if_dot == 0)
		fmt_new->if_hash = 1;
	if (str == '.')
		fmt_new->if_dot = 1;
}

t_format		*def_format(char *param_start, char *param_end, va_list param)
{
	t_format	*fmt_new;

	fmt_new = (t_format *)malloc(sizeof(t_format));
	if (!fmt_new)
		return (0);
	init_format(fmt_new);
	while (param_start < param_end)
	{
		put_format(*param_start, fmt_new);
		param_start++;
		if (*param_start < '9' && *param_start > '0')
			break ;
	}
	if (*param_start < '9' && *param_start > '0')
		put_length(param_start, fmt_new);
	fmt_new->type = *param_end;
	return (fmt_new);
}
