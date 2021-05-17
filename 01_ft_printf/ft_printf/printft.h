/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:43:09 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/17 20:57:30 by jiychoi          ###   ########.fr       */
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
	** the most important main function : ft_printf
*/
int		ft_printf(const char *, ...);

/*
	** utilities : for handling strings, etc
*/
char	*ft_strchr(const char *src, int c);
char	*ft_strnchr(const char *src, const char *dst, int c);
int		ft_write_until(const char *src, const char *dst);
int		if_available(char s, char *arr);
size_t	ft_strlen(const char *s)

char	*ft_itoa(int n);
int			ft_atoi(const char *str);

#endif
