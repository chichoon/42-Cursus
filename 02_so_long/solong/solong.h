/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:48:57 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/16 15:44:54 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h> //strerror
# include <stdio.h> //perror

# include "mlx_opengl/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

/*
	** structure : for map
*/
typedef struct	s_map_info
{
	size_t	map_width;
	size_t	map_height;
	size_t	num_collections;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}				t_map_info;

typedef struct	s_map_img
{
	void *map_up_left;
	void *map_up_mid;
	void *map_up_right;
	void *map_mid_left;
	void *map_mid_mid;
	void *map_mid_right;
	void *map_down_left;
	void *map_down_mid;
	void *map_down_right;
	void *map_pillar0;
	void *map_pillar1;
	void *map_pillar2;
}				t_map_img;

typedef struct	s_char_img
{
	void *char_e0;
	void *char_e1;
	void *char_w0;
	void *char_w1;
	void *char_n0;
	void *char_n1;
	void *char_s0;
	void *char_s1;
	void *item0;
	void *item1;
	void *enem0;
	void *enem1;
}				t_char_img;

typedef struct	s_solong
{
	t_map_info	*info;
	t_map_img	*img_map;
	t_char_img	*img_char;
}				t_solong;

/*
	so_long : Parse map
*/
char			**sol_parse_map(char *filename, t_map_info *info);
int				sol_perror_return(char *str, t_map_info *info);
int				sol_check_map(char *filename, t_map_info *info);
int				sol_validate_map(char **map, t_map_info *info);

/*
	so_long : Initialize & free mlx pointers
*/
void			sol_init_mlxptr(t_map_info *info);
void			sol_init_mapimg(t_map_img *img, t_map_info *info, int temp);
void			sol_init_charimg(t_char_img *img, t_map_info *info, int temp);
void			sol_free_mapimg(t_map_img *img, t_map_info *info);
void			sol_free_charimg(t_char_img *img, t_map_info *info);

/*
	so_long : Draw map
*/
void			sol_draw_corner(t_map_info *info, t_map_img *img);
void			sol_draw_ywall(t_map_info *info, t_map_img *img);
void			sol_draw_xwall(t_map_info *info, t_map_img *img);
void			sol_draw_pillar(int x, int y, t_map_info *info, t_map_img *img);
void			sol_draw_map(char **map, t_map_info *info, t_map_img *img);

void	so_long(char **map, t_map_info *info);

/*
	utils!
*/
char			*ft_strstr(char *str, char *to_find);
char			**ft_free_char2d(char **arr);
int				ft_if_available(char s, char *arr);

#endif
