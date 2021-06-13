/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_validate_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 15:38:24 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/13 17:00:33 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	sol_check_wall(char **map, t_map_info *info)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (++y < (int)info->map_height)
	{
		if (map[y][0] != '1')
			return (0);
		if (map[y][info->map_width - 1] != '1')
			return (0);
	}
	while (++x < (int)info->map_width)
	{
		if (map[0][x] != '1')
			return (0);
		if (map[info->map_height - 1][x] != '1')
			return (0);
	}
	return (1);
}

static int	sol_check_char(char **map, t_map_info *info)
{
	int num_exit;
	int num_start;
	int x;
	int y;

	num_exit = 0;
	num_start = 0;
	y = -1;
	while (++y < (int)info->map_height)
	{
		x = -1;
		while(++x < (int)info->map_width)
		{
			if (!ft_if_available(map[y][x], "01CEP"))
				return (0);
			if (map[y][x] == 'E')
				num_exit++;
			if (map[y][x] == 'P')
				num_start++;
		}
	}
	if (num_exit < 1 || num_start != 1)
		return (0);
	return (1);
}

static int	sol_count_collective(char **map, t_map_info *info)
{
	int x;
	int y;

	y = -1;
	while (++y < (int)info->map_height)
	{
		x = -1;
		while (++x < (int)info->map_width)
			if (map[y][x] == 'C')
				info->num_collections++;
	}
	if (info->num_collections < 1)
		return (0);
	return (1);
}

int		sol_validate_map(char **map, t_map_info *info)
{
	info->num_collections = 0;
	if (info->map_height < 3 || info->map_width < 3)
		return (sol_perror_return("Too small map", info));
	if (!sol_check_wall(map, info))
		return (sol_perror_return("Map is not closed", info));
	if (!sol_check_char(map, info))
		return (sol_perror_return("Invalid map charset", info));
	if (!sol_count_collective(map, info))
		return (sol_perror_return("Too small collectives", info));
	printf("collective: %zu\n", info->num_collections);
	return (1);
}
