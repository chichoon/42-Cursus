/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_screen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:02:51 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/13 20:47:34 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sol_draw_corner(char **map, t_map_info *info)
{
	if (map[0][0] == '1')
	{
		mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr, info->img_ptr,
			0, 0, 32, 32, 0, 0, 64, 64, 0xFFFFFFFF);
	}
	if (map[0][info->map_width - 1] == '1')
	{
		mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr, info->img_ptr,
			64, 0, 32, 32, info->map_width * 64 - 64, 0,
			64, 64, 0xFFFFFFFF);
	}
	if (map[info->map_height - 1][0] == '1')
	{
		mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr, info->img_ptr,
			0, 64, 32, 32, 0, info->map_height * 64 - 64,
			64, 64, 0xFFFFFFFF);
	}
	if (map[info->map_height - 1][info->map_width - 1] == '1')
	{
		mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr, info->img_ptr,
			64, 64, 32, 32, info->map_width * 64 - 64, info->map_height * 64 - 64,
			64, 64, 0xFFFFFFFF);
	}
}

void	sol_draw_ywall(char **map, t_map_info *info)
{
	int y;

	y = 0;
	while (++y + 1 < (int)info->map_height)
	{
		if (map[y][0] == '1')
		{
			mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr,
				info->img_ptr, 0, 32, 32, 32, 0,
				y * 64, 64, 64, 0xFFFFFFFF);
		}
		if (map[y][info->map_width - 1] == '1')
		{
			mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr,
				info->img_ptr, 64, 32, 32, 32, info->map_width * 64 - 64,
				y * 64, 64, 64, 0xFFFFFFFF);
		}
	}
}

void	sol_draw_xwall(char **map, t_map_info *info)
{
	int x;

	x = 0;
	while (++x + 1 < (int)info->map_width)
	{
		if (map[0][x] == '1')
		{
			mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr,
				info->img_ptr, 32, 0, 32, 32, x * 64,
				0, 64, 64, 0xFFFFFFFF);
		}
		if (map[info->map_height - 1][x] == '1')
		{
			mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr,
				info->img_ptr, 32, 64, 32, 32, x * 64,
				info->map_height * 64 - 64, 64, 64, 0xFFFFFFFF);
		}
	}
}

void	sol_draw_map(char **map, t_map_info *info)
{
	int x;
	int y;

	y = 0;
	while (++y + 1 < (int)info->map_height)
	{
		x = 0;
		while (++x + 1 < (int)info->map_width)
		{
			if (map[y][x] == '1')
			{
				mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr,
					info->img_ptr, 32, 96, 32, 32, x * 64,
					y * 64, 64, 64, 0xFFFFFFFF);
			}
			else
			{
				mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr,
					info->img_ptr, 32, 32, 32, 32, x * 64,
					y * 64, 64, 64, 0xFFFFFFFF);
			}
		}
	}
}

void	so_long(char **map, t_map_info *info)
{
	int		temp;

	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, info->map_width * 64,
		info->map_height * 64, "so_long");
	info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, "charset.xpm",
		&temp, &temp);
	sol_draw_corner(map, info);
	sol_draw_ywall(map, info);
	sol_draw_xwall(map, info);
	sol_draw_map(map, info);
	mlx_loop(info->mlx_ptr);
}
