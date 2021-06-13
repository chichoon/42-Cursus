/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:58:28 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/13 12:06:08 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int deal_key(int key, void *param)
{
	ft_putchar('-');
	printf("put : %d\n", key);
	printf("%p\n", param);
	if (key == 53)
		exit(0);
	return (key);
}

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	void *coa_lee;
	void *coa_gam;
	int width;
	int height;

	mlx_ptr = mlx_init(); //보이드 포인터를 리턴함, 그래픽 서버에 접속하는 함수
	win_ptr = mlx_new_window(mlx_ptr, 640, 480, "hello");
	coa_lee = mlx_xpm_file_to_image(mlx_ptr, "coa_4.XPM", &width, &height);
	coa_gam = mlx_xpm_file_to_image(mlx_ptr, "coa_3.XPM", &width, &height);
	printf("%d\n", width);
	mlx_pixel_put(mlx_ptr, win_ptr, 20, 20, 0xFFFFFF);
	mlx_put_image_to_window(mlx_ptr, win_ptr, coa_lee, 30, 30);
	mlx_put_image_to_window_scale(mlx_ptr, win_ptr, coa_gam, 0, 0, 16, 16, 200, 200, 128, 128, 0xFFFFFF);
	mlx_put_image_to_window_scale(mlx_ptr, win_ptr, coa_lee, 0, 0, 16, 16, 200, 200, 64, 64, 0xFFFFFFFF);
	mlx_put_image_to_window_scale(mlx_ptr, win_ptr, coa_gam, 0, 0, 16, 16, 200, 200, 32, 32, 0xFFFFFFFF);
	mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}
