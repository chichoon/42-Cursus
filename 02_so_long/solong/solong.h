/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:48:57 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/13 16:51:39 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h> //strerror
# include <stdio.h> //perror

# include "mlx/mlx.h"
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
}				t_map_info;

/*
	so_long : Parse map
*/
char			**sol_parse_map(char *filename, t_map_info *info);
int				sol_perror_return(char *str, t_map_info *info);
int				sol_check_map(char *filename, t_map_info *info);
int				sol_validate_map(char **map, t_map_info *info);

/*
	utils!
*/
char			*ft_strstr(char *str, char *to_find);
char			**ft_free_char2d(char **arr);
int				ft_if_available(char s, char *arr);

#endif
