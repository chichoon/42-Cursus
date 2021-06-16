/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:41:56 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/16 20:02:16 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sol_init_mlxptr(t_map_info *info)
{
	int x;
	int y;

	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, info->map_width * 32,
		info->map_height * 32, "so_long");
	y = -1;
	while (++y < (int)info->map_height)
	{
		x = -1;
		while (++x < (int)info->map_width)
		{
			if (info->map[y][x] == 'P')
			{
				info->char_x = x;
				info->char_y = y;
				info->char_pos = 's';
				info->move_count = 0;
				info->loop_flag = 0;
				return ;
			}
		}
	}
}

void	sol_init_mapimg(t_map_img *img, t_map_info *info, int temp)
{
	img->map_up_left = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/map_1_1.xpm", &temp, &temp);
	img->map_up_mid = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/map_1_2.xpm", &temp, &temp);
	img->map_up_right = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/map_1_3.xpm", &temp, &temp);
	img->map_mid_left = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/map_1_4.xpm", &temp, &temp);
	img->map_mid_mid = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/map_1_5.xpm", &temp, &temp);
	img->map_mid_right = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/map_1_6.xpm", &temp, &temp);
	img->map_down_left = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/map_1_7.xpm", &temp, &temp);
	img->map_down_mid = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/map_1_8.xpm", &temp, &temp);
	img->map_down_right = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/map_1_9.xpm", &temp, &temp);
	img->map_pillar0 = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/map_2_1.xpm", &temp, &temp);
	img->map_pillar1 = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/map_2_2.xpm", &temp, &temp);
	img->map_pillar2 = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/map_2_3.xpm", &temp, &temp);
}

void	sol_init_charimg(t_char_img *img, t_map_info *info, int temp)
{
	img->char_e0 = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/char_e.xpm", &temp, &temp);
	img->char_e1 = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/char_e2.xpm", &temp, &temp);
	img->char_w0 = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/char_w.xpm", &temp, &temp);
	img->char_w1 = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/char_w2.xpm", &temp, &temp);
	img->char_s0 = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/char_s.xpm", &temp, &temp);
	img->char_s1 = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/char_s2.xpm", &temp, &temp);
	img->char_n0 = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/char_n.xpm", &temp, &temp);
	img->char_n1 = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/char_n2.xpm", &temp, &temp);
	img->item0 = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/success.xpm", &temp, &temp);
	img->item1 = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/success_2.xpm", &temp, &temp);
	img->enem0 = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/fail.xpm", &temp, &temp);
	img->enem1 = mlx_xpm_file_to_image(info->mlx_ptr,
		"xpm/fail_2.xpm", &temp, &temp);
}

void	sol_free_mapimg(t_map_img *img, t_map_info *info)
{
	mlx_destroy_image(info->mlx_ptr, img->map_up_left);
	mlx_destroy_image(info->mlx_ptr, img->map_up_mid);
	mlx_destroy_image(info->mlx_ptr, img->map_up_right);
	mlx_destroy_image(info->mlx_ptr, img->map_mid_left);
	mlx_destroy_image(info->mlx_ptr, img->map_mid_mid);
	mlx_destroy_image(info->mlx_ptr, img->map_mid_right);
	mlx_destroy_image(info->mlx_ptr, img->map_down_left);
	mlx_destroy_image(info->mlx_ptr, img->map_down_mid);
	mlx_destroy_image(info->mlx_ptr, img->map_down_right);
	mlx_destroy_image(info->mlx_ptr, img->map_pillar0);
	mlx_destroy_image(info->mlx_ptr, img->map_pillar1);
	mlx_destroy_image(info->mlx_ptr, img->map_pillar2);
	mlx_destroy_image(info->mlx_ptr, img->map_end);
	free(img);
}

void	sol_free_charimg(t_char_img *img, t_map_info *info)
{
	mlx_destroy_image(info->mlx_ptr, img->char_e0);
	mlx_destroy_image(info->mlx_ptr, img->char_e1);
	mlx_destroy_image(info->mlx_ptr, img->char_w0);
	mlx_destroy_image(info->mlx_ptr, img->char_w1);
	mlx_destroy_image(info->mlx_ptr, img->char_s0);
	mlx_destroy_image(info->mlx_ptr, img->char_s1);
	mlx_destroy_image(info->mlx_ptr, img->char_n0);
	mlx_destroy_image(info->mlx_ptr, img->char_n1);
	mlx_destroy_image(info->mlx_ptr, img->item0);
	mlx_destroy_image(info->mlx_ptr, img->item1);
	mlx_destroy_image(info->mlx_ptr, img->enem0);
	mlx_destroy_image(info->mlx_ptr, img->enem1);
	free(img);
}
