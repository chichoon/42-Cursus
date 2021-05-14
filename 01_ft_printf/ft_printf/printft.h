/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:43:09 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/14 20:15:44 by jiychoi          ###   ########.fr       */
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
char	*ft_strchr(const char *src, int c);
int		ft_write_until(const char *src, const char *dst);
int		if_available(char s, char *arr);

#endif
