/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:48:13 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/15 20:53:36 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	so_long(char **map, t_map_info *info)
{
	int		temp;
	int		x;
	int 	y;
	void	*img_temp;

	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, info->map_width * 64,
		info->map_height * 64, "so_long");
	img_temp = mlx_xpm_file_to_image(info->mlx_ptr, "char123.xpm", &temp, &temp);
	info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, "charset.xpm",
		&temp, &temp);
	x = 0;
	while (x < (int)info->map_width)
	{
		y = 0;
		while (y < (int)info->map_height)
		{
			mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, img_temp,
			x * 64, y * 64);
			y++;
		}
		x++;
	}
	sol_draw_corner(info);
	sol_draw_ywall(info);
	sol_draw_xwall(info);
	sol_draw_map(map, info);
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
