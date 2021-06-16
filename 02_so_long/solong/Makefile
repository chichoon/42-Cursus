# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 14:50:22 by jiychoi           #+#    #+#              #
#    Updated: 2021/06/16 15:56:48 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MFLAGS		=	-g3 -fsanitize=address
SRC			=	so_long_main.c so_long_utils.c so_long_parse_map.c \
				so_long_validate_map.c so_long_draw_screen.c\
				so_long_init_struct.c\
				gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ			=	$(SRC:.c=.o)
LIBFT		=	-L ./libft -lft
MLX_OPENGL	=	-L ./mlx_opengl -lmlx
MLX_FLAGS	=	-framework OpenGL -framework Appkit
TARGET		=	so_long

all : $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I ./

$(TARGET) : $(OBJ)
	@$(MAKE) -C ./mlx_opengl all
	@mv ./mlx_opengl/libmlx.a ./libmlx.a
	@$(MAKE) -C ./libft all
	$(CC) $(SRC) $(CFLAGS) $(MLX_OPENGL) $(MLX_FLAGS) $(LIBFT) -o $(TARGET)

clean :
	rm -rf $(OBJ)
	cd ./mlx_opengl && make clean
	cd ./libft && make fclean

fclean : clean
	rm -rf $(TARGET)
	rm -rf libmlx.a
	rm -rf so_long.dSYM

re : fclean all
