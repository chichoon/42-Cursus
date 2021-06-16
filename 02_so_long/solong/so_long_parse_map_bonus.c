/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse_map_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:48:45 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/16 21:57:21 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

char	**sol_parse_map(char *filename, t_map_info *info)
{
	int		fd_map;
	char	**map;
	int		index;

	index = 0;
	fd_map = open(filename, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * (info->map_height + 1));
	while (get_next_line(fd_map, &map[index]) > 0)
		index++;
	if (ft_strlen(map[index]) == 0)
	{
		free(map[index]);
		map[index] = 0;
	}
	return (map);
}

int		sol_perror_return(char *str, t_map_info *info)
{
	ft_putstr_fd(str, 0);
	if (info)
	{
		info->map_height = 0;
		info->map_width = 0;
		free(info);
	}
	return (0);
}

int		sol_check_map(char *filename, t_map_info *info)
{
	int		fd_map;
	char	*str;
	int		gnl_result;

	fd_map = open(filename, O_RDONLY);
	if (fd_map < 3)
		return (sol_perror_return("No such file", info));
	gnl_result = get_next_line(fd_map, &str);
	info->map_width = ft_strlen(str);
	info->map_height = 0;
	while (gnl_result > 0)
	{
		if (ft_strlen(str) != info->map_width)
		{
			close(fd_map);
			free(str);
			return (sol_perror_return("Invalid rectangle shape", info));
		}
		free(str);
		info->map_height++;
		gnl_result = get_next_line(fd_map, &str);
	}
	free(str);
	close(fd_map);
	return (1);
}
