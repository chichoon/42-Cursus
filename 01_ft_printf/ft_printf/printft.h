/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:43:09 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/19 14:46:44 by jiychoi          ###   ########.fr       */
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
	int		if_asterisk_width;
	int		if_asterisk_precision;
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
int				if_available(char s, char *arr);
size_t			ft_strlen(const char *s);

int				ft_putstr_until(const char *src, const char *dst);
int				ft_putstr(const char *src);

char			*ft_itoa_base(unsigned int absol, char *base);
int				ft_atoi(const char *str);
void			*ft_memset(void *ptr, int value, size_t n);
int				free_and_return(void *ptr);

#endif
