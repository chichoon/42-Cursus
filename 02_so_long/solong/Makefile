# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 14:50:22 by jiychoi           #+#    #+#              #
#    Updated: 2021/06/15 18:46:47 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MFLAGS		=	-g3 -fsanitize=address
SRC			=	so_long_main.c so_long_utils.c so_long_parse_map.c \
				so_long_validate_map.c so_long_draw_screen.c\
				gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ			=	$(SRC:.c=.o)
LIBFT		=	-L ./libft -lft
MLX			=	-L ./mlx -lmlx -framework OpenGL -framework Appkit
TARGET		=	so_long

all : $(TARGET)
	install_name_tool -change libmlx.dylib ./mlx/libmlx.dylib $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I ./

$(TARGET) : $(OBJ)
	$(MAKE) -C ./mlx all
	$(MAKE) -C ./libft all
	$(CC) $(SRC) $(CFLAGS) $(MFLAGS) $(MLX) $(LIBFT) -o $(TARGET)
#	$(CC) $(SRC) $(CFLAGS) $(MLX) $(LIBFT) -o $(TARGET)

clean :
	rm -rf $(OBJ)
	rm -rf libmlx.dylib
	cd ./mlx && make clean
	cd ./libft && make fclean

fclean : clean
	rm -rf $(TARGET)
	rm -rf ./mlx/libmlx.dylib

re : fclean all
