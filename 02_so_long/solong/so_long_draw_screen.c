/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_screen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:02:51 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/15 20:38:12 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_mms/mlx.h"
#include "solong.h"

void	sol_draw_corner(t_map_info *info)
{
	mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr, info->img_ptr,
		0, 0, 32, 32, 0, 0, 64, 64, 0xFFFFFFFF);
	mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr, info->img_ptr,
		64, 0, 32, 32, info->map_width * 64 - 64, 0,
		64, 64, 0xFFFFFFFF);
	mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr, info->img_ptr,
		0, 64, 32, 32, 0, info->map_height * 64 - 64,
		64, 64, 0xFFFFFFFF);
	mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr, info->img_ptr,
		64, 64, 32, 32, info->map_width * 64 - 64, info->map_height * 64 - 64,
		64, 64, 0xFFFFFFFF);
}

void	sol_draw_ywall(t_map_info *info)
{
	int y;

	y = 0;
	while (++y + 1 < (int)info->map_height)
	{
		mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr,
			info->img_ptr, 0, 32, 32, 32, 0, y * 64, 64, 64, 0xFFFFFFFF);
		mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr,
			info->img_ptr, 64, 32, 32, 32, info->map_width * 64 - 64,
			y * 64, 64, 64, 0xFFFFFFFF);
	}
}

void	sol_draw_xwall(t_map_info *info)
{
	int x;

	x = 0;
	while (++x + 1 < (int)info->map_width)
	{
		mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr,
			info->img_ptr, 32, 0, 32, 32, x * 64,
			0, 64, 64, 0xFFFFFFFF);
		mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr,
			info->img_ptr, 32, 64, 32, 32, x * 64,
			info->map_height * 64 - 64, 64, 64, 0xFFFFFFFF);
	}
}

void	sol_draw_pillar(int x, int y, t_map_info *info)
{
	if (x % 3 == 1 && y % 2 == 1)
	{
		mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr,
					info->img_ptr, 0, 96, 32, 32, x * 64,
					y * 64, 64, 64, 0xFFFFFFFF);
	}
	else if (x % 3 == 0 && y % 2 == 0)
	{
		mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr,
					info->img_ptr, 64, 96, 32, 32, x * 64,
					y * 64, 64, 64, 0xFFFFFFFF);
	}
	else
	{
		mlx_put_image_to_window_scale(info->mlx_ptr, info->win_ptr,
			info->img_ptr, 32, 96, 32, 32, x * 64,
			y * 64, 64, 64, 0xFFFFFFFF);
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
				sol_draw_pillar(x, y, info);
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
