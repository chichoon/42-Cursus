/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:02:57 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/20 14:03:10 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

int			print_if_minus_c(char c, int wtp)
{
	int output;

	output = 0;
	write(1, &c, 1);
	output++;
	while (wtp--)
	{
		output++;
		write(1, " ", 1);
	}
	return (output);
}

int			print_no_flags_c(char c, int wtp)
{
	int output;

	output = 0;
	while (wtp--)
	{
		output++;
		write(1, " ", 1);
	}
	write(1, &c, 1);
	output++;
	return (output);
}
