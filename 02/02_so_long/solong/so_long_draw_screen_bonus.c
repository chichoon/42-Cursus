/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_screen_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:02:51 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/30 23:06:39 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	sol_draw_corner(t_map_info *info, t_map_img *img)
{
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, img->map_up_left,
		0, 0);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, img->map_up_right,
		info->map_width * 32 - 32, 0);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, img->map_down_left,
		0, info->map_height * 32 - 32);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, img->map_down_right,
		info->map_width * 32 - 32, info->map_height * 32 - 32);
}

void	sol_draw_ywall(t_map_info *info, t_map_img *img)
{
	int	y;

	y = 0;
	while (++y + 1 < (int)info->map_height)
	{
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
			img->map_mid_left, 0, y * 32);
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
			img->map_mid_right, info->map_width * 32 - 32, y * 32);
	}
}

void	sol_draw_xwall(t_map_info *info, t_map_img *img)
{
	int	x;

	x = 0;
	while (++x + 1 < (int)info->map_width)
	{
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
			img->map_up_mid, x * 32, 0);
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
			img->map_down_mid, x * 32, info->map_height * 32 - 32);
	}
}

void	sol_draw_pillar(int x, int y, t_map_info *info, t_map_img *img)
{
	if (x % 3 == 1 && y % 2 == 1)
	{
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
			img->map_pillar0, x * 32, y * 32);
	}
	else if (x % 3 == 0 && y % 2 == 0)
	{
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
			img->map_pillar2, x * 32, y * 32);
	}
	else
	{
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
			img->map_pillar1, x * 32, y * 32);
	}
}

void	sol_draw_map(t_map_info *info, t_map_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (++y + 1 < (int)info->map_height)
	{
		x = 0;
		while (++x + 1 < (int)info->map_width)
		{
			if (info->map[y][x] == '1')
				sol_draw_pillar(x, y, info, img);
			else if (info->map[y][x] == 'E')
			{
				mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
					img->map_end, x * 32, y * 32);
			}
			else
			{
				mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
					img->map_mid_mid, x * 32, y * 32);
			}
		}
	}
}
