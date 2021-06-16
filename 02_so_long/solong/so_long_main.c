/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:48:13 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/16 15:55:19 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int		so_long_key(int key, void *param)
{
	t_solong	*str_solong;

	str_solong = (t_solong *)param;
	if (key == 53)
	{
		sol_free_mapimg(str_solong->img_map, str_solong->info);
		sol_free_charimg(str_solong->img_char, str_solong->info);
		mlx_destroy_window(str_solong->info->mlx_ptr, str_solong->info->win_ptr);
		exit(0);
	}
	return (key);
}

void	so_long(char **map, t_map_info *info)
{
	t_solong	*str_solong;
	int			temp;

	temp = 0;
	str_solong = (t_solong *)malloc(sizeof(t_solong));
	sol_init_mlxptr(info);
	str_solong->info = info;
	str_solong->img_map = (t_map_img *)malloc(sizeof(t_map_img));
	str_solong->img_char = (t_char_img *)malloc(sizeof(t_char_img));
	sol_init_mapimg(str_solong->img_map, str_solong->info, temp);
	sol_init_charimg(str_solong->img_char, str_solong->info, temp);
	sol_draw_corner(str_solong->info, str_solong->img_map);
	sol_draw_ywall(str_solong->info, str_solong->img_map);
	sol_draw_xwall(str_solong->info, str_solong->img_map);
	sol_draw_map(map, str_solong->info, str_solong->img_map);
	mlx_key_hook(str_solong->info->win_ptr, so_long_key, str_solong);
	mlx_loop(info->mlx_ptr);
}

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
