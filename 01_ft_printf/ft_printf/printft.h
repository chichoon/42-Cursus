/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:43:09 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/18 23:02:44 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFT_H
# define PRINTFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //erase this!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//# include "libft.h"

/*
	** structure : for maintain flags, conventions
*/
typedef struct	s_format
{
	char	type;
	int		width;
	int		precision;
	int		if_dot;
	int		if_zero;
	int		if_minus;
	int		if_plus;
	int		if_space;
	int		if_hash;
}				t_format;

/*
	** the most important main function : ft_printf
*/
int				ft_printf(const char *, ...);

/*
	** functions for get format : flag 0-+ #.
*/
t_format		*def_format(char *param_start, char *param_end, va_list param);

/*
	** functions for conventions : cspdiuxX, %
*/
int				ft_print_c(t_format *fmt_conv, va_list param);
int				ft_print_s(t_format *fmt_conv, va_list param);
int				ft_print_p(t_format *fmt_conv, va_list param);
int				ft_print_d(t_format *fmt_conv, va_list param);
int				ft_print_i(t_format *fmt_conv, va_list param);
int				ft_print_u(t_format *fmt_conv, va_list param);
int				ft_print_lowx(t_format *fmt_conv, va_list param);
int				ft_print_uppx(t_format *fmt_conv, va_list param);

/*
	** utilities : for handling strings, etc
*/
char			*ft_strchr(const char *src, int c);
char			*ft_strnchr(const char *src, const char *dst, int c);
int				ft_write_until(const char *src, const char *dst);
int				if_available(char s, char *arr);
size_t			ft_strlen(const char *s);

char			*ft_itoa(int n);
int				ft_atoi(const char *str);
void			*ft_memset(void *ptr, int value, size_t n);

#endif
