/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:43:09 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/30 23:03:29 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFT_H
# define PRINTFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/*
	** structure : for maintain flags, conventions
*/
typedef struct s_format
{
	char	type;
	int		width;
	int		precision;
	int		if_dot;
	int		if_zero;
	int		if_minus;
	int		if_asterisk_width;
	int		if_asterisk_precision;
}				t_format;

/*
	** the most important main function : ft_printf
*/
int				ft_printf(const char *fmt, ...);

/*
	** functions for get format : flag 0-+ #.
*/
t_format		*def_format(char *param_start, char *param_end);

/*
	** functions for conventions : cspdiuxX, %
*/
int				ft_print_c(t_format *fmt_conv, va_list param);
int				ft_print_s(t_format *fmt_conv, va_list param);
int				ft_print_p(t_format *fmt_conv, va_list param);

int				ft_print_d(t_format *fmt_conv, va_list param);
int				ft_print_i(t_format *fmt_conv, va_list param);
int				ft_print_u(t_format *fmt_conv, va_list param);
int				ft_print_x(t_format *fmt_conv, va_list param, int if_low);
char			*check_if_percent(char *ptr_param);

/*
	** functions for actual printing
*/
int				print_ctrltwr_c(t_format *fmt_conv, char c);
int				print_ctrltwr_s(t_format *fmt_conv, char *str);
int				print_ctrltwr_p(t_format *fmt_conv, char *str);
int				print_if_minus_c(char c, int wtp);
int				print_if_zero_c(char c, int wtp);
int				print_no_flags_c(char c, int wtp);
int				print_if_minus_s(char *str, int wtp, int length);
int				print_no_flags_s(char *str, int wtp, int length);

int				print_ctrltwr_diux(t_format *fmt_conv, char *nb, int if_pos);
int				print_if_minus(char *nb, int wtp, int ptp);
int				print_if_zero(char *nb, int wtp);
int				print_no_flags(char *nb, int wtp, int ptp);
int				print_neg_if_minus(char *nb, int wtp, int ptp);
int				print_neg_if_zero(char *nb, int wtp);
int				print_neg_no_flags(char *nb, int wtp, int ptp);

int				print_if_zero_s(char *str, int wtp, int length);
int				print_no_flags_p(char *nb, int wtp, int ptp);
int				print_if_minus_p(char *nb, int wtp, int ptp);
int				print_if_zero_p(char *nb, int wtp, int ptp);

/*
	** utilities : for handling strings, etc
*/
char			*ft_strchr_pf(const char *src, int c);
int				if_available(char s, char *arr);
size_t			ft_strlen_pf(const char *s);
int				ft_putstr_until(const char *src, const char *dst);
int				ft_putstr_pf(const char *src);

char			*ft_itoa_base(unsigned long absol, char *base);
int				ft_atoi_pf(const char *str);
void			*ft_memset(void *ptr, int value, size_t n);
void			*free_and_return(void *ptr);
char			*ft_strjoin_pf(char const *s1, char const *s2);

#endif
