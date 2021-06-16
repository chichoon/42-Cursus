/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:48:13 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/16 20:38:09 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int		so_long_key(int key, void *param)
{
	t_solong	*str_solong;

	str_solong = (t_solong *)param;
	if (key == 53)
		sol_exit(str_solong);
	else if (key == 13 || key == 126)
		sol_move_up(str_solong);
	else if (key == 0 || key == 123)
		sol_move_left(str_solong);
	else if (key == 1 || key == 125)
		sol_move_down(str_solong);
	else if (key == 2 || key == 124)
		sol_move_right(str_solong);
	return (key);
}

void	so_long_draw_map(t_solong *str_solong)
{
	sol_draw_corner(str_solong->info, str_solong->img_map);
	sol_draw_ywall(str_solong->info, str_solong->img_map);
	sol_draw_xwall(str_solong->info, str_solong->img_map);
	sol_draw_map(str_solong->info, str_solong->img_map);
}

int		so_long_main_loop(t_solong *str_solong)
{
	t_map_info	*info;
	t_char_img	*img;

	info = str_solong->info;
	img = str_solong->img_char;
	if (info->loop_flag == 100)
		info->loop_flag = 0;
	else
		info->loop_flag++;
	so_long_draw_map(str_solong);
	so_long_draw_char(str_solong);
	sol_draw_collective(str_solong->info, str_solong->img_char);
	sol_char_pos_event(str_solong);
	sol_draw_move_count(str_solong);
	return (0);
}

void	so_long(t_map_info *info)
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
	str_solong->img_map->map_end = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/end.xpm", &temp, &temp);
	sol_init_charimg(str_solong->img_char, str_solong->info, temp);
	so_long_draw_map(str_solong);
	mlx_hook(str_solong->info->win_ptr, 17, 0, sol_exit, str_solong);
	mlx_key_hook(str_solong->info->win_ptr, so_long_key, str_solong);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
		str_solong->img_char->char_s0, info->char_x * 32, info->char_y * 32);
	mlx_loop_hook(info->mlx_ptr, so_long_main_loop, str_solong);
	mlx_loop(info->mlx_ptr);
}

int		main(int argc, char *argv[])
{
	char		**map;
	char		*ptr;
	t_map_info	*map_info;

	if (argc == 2)
	{
		ptr = ft_strstr(argv[1], ".ber");
		if (!ptr || *(ptr + 4) != 0)
			return (sol_perror_return("Invalid file extension", 0));
		map_info = (t_map_info *)malloc(sizeof(t_map_info));
		if (!sol_check_map(argv[1], map_info))
			return (0);
		map = sol_parse_map(argv[1], map_info);
		if (!sol_validate_map(map, map_info))
			return ((int)ft_free_char2d(map));
		map_info->map = map;
		so_long(map_info);
	}
	else
	{
		perror("Invalid argument number");
		exit(1);
	}
}
