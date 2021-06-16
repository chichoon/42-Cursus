/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_assets_2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 21:06:58 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/16 21:57:03 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	sol_enemy_pos(t_solong *str_solong)
{
	t_map_info	*info;
	t_char_img	*img;
	int			num_enems;
	int			x;
	int			y;

	info = str_solong->info;
	img = str_solong->img_char;
	num_enems = 0;
	y = -1;
	while (++y < (int)info->map_height)
	{
		x = -1;
		while (++x < (int)info->map_width)
		{
			if (info->map[y][x] == '0' &&
				((y % 5 == 4 && x % 5 == 3) || (y % 5 == 2 && x % 7 == 1)))
				if (num_enems < (int)info->num_collections * 2)
					info->map[y][x] = 'V';
		}
	}
}

void	sol_draw_enemy(t_map_info *info, t_char_img *img)
{
	int x;
	int y;

	y = -1;
	while (++y < (int)info->map_height)
	{
		x = -1;
		while (++x < (int)info->map_width)
		{
			if (info->map[y][x] == 'V')
			{
				if (info->loop_flag % 50 < 25)
				{
					mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
						img->enem0, x * 32, y * 32);
				}
				else
				{
					mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
						img->enem1, x * 32, y * 32);
				}
			}
		}
	}
}
