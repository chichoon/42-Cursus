/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:58:28 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/12 20:11:48 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int deal_key(int key, void *param)
{
	ft_putchar('-');
	printf("put : %d\n", key);
	return (key);
}

int main()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init(); //보이드 포인터를 리턴함, 그래픽 서버에 접속하는 함수
	win_ptr = mlx_new_window(mlx_ptr, 640, 480, "hello");
	mlx_pixel_put(mlx_ptr, win_ptr, 20, 20, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}
