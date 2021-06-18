/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 18:20:14 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/17 13:23:29 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sol_move_up(t_solong *str_solong)
{
	t_map_info *info;

	info = str_solong->info;
	info->char_pos = 'n';
	info->char_y -= 1;
	if (info->map[info->char_y][info->char_x] == '1')
		info->char_y += 1;
	info->move_count++;
	ft_putnbr_fd(info->move_count, 1);
	ft_putchar_fd('\n', 1);
}

void	sol_move_left(t_solong *str_solong)
{
	t_map_info *info;

	info = str_solong->info;
	info->char_pos = 'w';
	info->char_x -= 1;
	if (info->map[info->char_y][info->char_x] == '1')
		info->char_x += 1;
	info->move_count++;
	ft_putnbr_fd(info->move_count, 1);
	ft_putchar_fd('\n', 1);
}

void	sol_move_down(t_solong *str_solong)
{
	t_map_info *info;

	info = str_solong->info;
	info->char_pos = 's';
	info->char_y += 1;
	if (info->map[info->char_y][info->char_x] == '1')
		info->char_y -= 1;
	info->move_count++;
	ft_putnbr_fd(info->move_count, 1);
	ft_putchar_fd('\n', 1);
}

void	sol_move_right(t_solong *str_solong)
{
	t_map_info *info;

	info = str_solong->info;
	info->char_pos = 'e';
	info->char_x += 1;
	if (info->map[info->char_y][info->char_x] == '1')
		info->char_x -= 1;
	info->move_count++;
	ft_putnbr_fd(info->move_count, 1);
	ft_putchar_fd('\n', 1);
}

void	so_long_draw_char(t_solong *str_solong)
{
	if (str_solong->info->char_pos == 'n')
		sol_draw_character_n(str_solong);
	else if (str_solong->info->char_pos == 's')
		sol_draw_character_s(str_solong);
	else if (str_solong->info->char_pos == 'w')
		sol_draw_character_w(str_solong);
	else if (str_solong->info->char_pos == 'e')
		sol_draw_character_e(str_solong);
}
