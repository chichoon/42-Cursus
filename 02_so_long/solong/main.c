/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:48:13 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/08 15:26:19 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		char	**map;
		int		fd_map;

		fd_map = open(argv[1])
		map = sol_parse_map();
		solong(map);
	}
	else
	{
		ft_putstr("Too many arguments!")
		exit(1)
	}
}
