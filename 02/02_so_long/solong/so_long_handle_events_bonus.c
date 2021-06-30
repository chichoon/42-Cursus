/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_handle_events_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:20:20 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/30 23:06:58 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	sol_draw_move_count(t_solong *str_solong)
{
	t_map_info	*info;
	t_char_img	*img;
	char		*movement;

	info = str_solong->info;
	img = str_solong->img_char;
	movement = ft_itoa(info->move_count);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
		str_solong->img_map->map_down_left, 0, info->map_height * 32 - 32);
	mlx_string_put(info->mlx_ptr, info->win_ptr, 0,
		info->map_height * 32 - 32, 0xFFFFFF, movement);
	free(movement);
}

void	sol_char_pos_event(t_solong *str_solong)
{
	t_map_info	*info;
	t_char_img	*img;

	info = str_solong->info;
	img = str_solong->img_char;
	if (info->map[info->char_y][info->char_x] == 'C')
	{
		info->num_collections--;
		info->map[info->char_y][info->char_x] = '0';
	}
	else if (info->map[info->char_y][info->char_x] == 'E')
	{
		if (info->num_collections == 0)
			sol_exit(str_solong);
	}
	else if (info->map[info->char_y][info->char_x] == 'V')
		sol_exit(str_solong);
}

int	sol_exit(t_solong *str_solong)
{
	sol_free_mapimg(str_solong->img_map, str_solong->info);
	sol_free_charimg(str_solong->img_char, str_solong->info);
	mlx_destroy_window(str_solong->info->mlx_ptr,
		str_solong->info->win_ptr);
	ft_free_char2d(str_solong->info->map);
	free(str_solong->info);
	exit(0);
	return (0);
}
