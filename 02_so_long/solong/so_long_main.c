/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:48:13 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/13 17:05:13 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int			main(int argc, char *argv[])
{
	char		**map;
	char		*ptr;
	t_map_info	*map_info;
	if (argc == 2)
	{
		ptr = ft_strstr(argv[1], ".ber");
		if (!ptr || *(ptr + 4) != 0)
			return(sol_perror_return("Invalid file extension", 0));
		map_info = (t_map_info *)malloc(sizeof(t_map_info));
		if (!sol_check_map(argv[1], map_info))
			return (0);
		map = sol_parse_map(argv[1], map_info);
		if (!sol_validate_map(map, map_info))
			return ((int)ft_free_char2d(map));
		so_long(map, map_info);
	}
	else
	{
		perror("Invalid argument number");
		exit(1);
	}
}
