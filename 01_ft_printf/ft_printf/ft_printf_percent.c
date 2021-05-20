/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:24:49 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/21 02:06:48 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

char	*check_if_percent(char *ptr_param)
{
	char *ptr_until;

	ptr_until = ft_strchr_pf(ptr_param, '%');
	if (!ptr_until)
		return (0);
	while (ptr_param < ptr_until)
	{
		if (!if_available(*ptr_param, "0-.*123456789"))
			return (0);
		ptr_param++;
	}
	return (ptr_until);
}
