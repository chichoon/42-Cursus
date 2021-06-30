/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_assets_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:09:56 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/30 23:06:05 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	sol_draw_character_n(t_solong *str_solong)
{
	t_map_info	*info;
	t_char_img	*img;

	info = str_solong->info;
	img = str_solong->img_char;
	if (info->loop_flag % 50 < 25)
	{
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
			img->char_n0, info->char_x * 32, info->char_y * 32);
	}
	else
	{
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
			img->char_n1, info->char_x * 32, info->char_y * 32);
	}
}

void	sol_draw_character_w(t_solong *str_solong)
{
	t_map_info	*info;
	t_char_img	*img;

	info = str_solong->info;
	img = str_solong->img_char;
	if (info->loop_flag % 50 < 25)
	{
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
			img->char_w0, info->char_x * 32, info->char_y * 32);
	}
	else
	{
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
			img->char_w1, info->char_x * 32, info->char_y * 32);
	}
}

void	sol_draw_character_s(t_solong *str_solong)
{
	t_map_info	*info;
	t_char_img	*img;

	info = str_solong->info;
	img = str_solong->img_char;
	if (info->loop_flag % 50 < 25)
	{
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
			img->char_s0, info->char_x * 32, info->char_y * 32);
	}
	else
	{
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
			img->char_s1, info->char_x * 32, info->char_y * 32);
	}
}

void	sol_draw_character_e(t_solong *str_solong)
{
	t_map_info	*info;
	t_char_img	*img;

	info = str_solong->info;
	img = str_solong->img_char;
	if (info->loop_flag % 50 < 25)
	{
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
			img->char_e0, info->char_x * 32, info->char_y * 32);
	}
	else
	{
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
			img->char_e1, info->char_x * 32, info->char_y * 32);
	}
}

void	sol_draw_collective(t_map_info *info, t_char_img *img)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (int)info->map_height)
	{
		x = -1;
		while (++x < (int)info->map_width)
		{
			if (info->map[y][x] == 'C')
			{
				if (info->loop_flag % 50 < 25)
				{
					mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
						img->item0, x * 32, y * 32);
				}
				else
				{
					mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
						img->item1, x * 32, y * 32);
				}
			}
		}
	}
}
