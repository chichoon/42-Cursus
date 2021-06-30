/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:15:23 by jiychoi           #+#    #+#             */
/*   Updated: 2021/05/08 20:49:08 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_recur(unsigned int n, int fd)
{
	char	c;

	if (n == 0)
		return ;
	ft_putnbr_recur(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	absol;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		absol = n * (-1);
	}
	else
		absol = n;
	ft_putnbr_recur(absol, fd);
}
