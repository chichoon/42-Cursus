# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 14:50:22 by jiychoi           #+#    #+#              #
#    Updated: 2021/06/15 20:37:03 by jiychoi          ###   ########.fr        #
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
MLX_MMS		=	-L ./mlx_mms -lm
MLX_OPENGL	=	-L ./mlx_opengl -lmlx
MLX_FLAGS	=	-framework OpenGL -framework Appkit
TARGET		=	so_long

all : $(TARGET)
	install_name_tool -change libmlx.dylib ./mlx_mms/libmlx.dylib $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I ./

$(TARGET) : $(OBJ)
	@$(MAKE) -C ./mlx_mms all
	@$(MAKE) -C ./mlx_opengl all
	@mv ./mlx_opengl/libmlx.a ./libm.a
	@$(MAKE) -C ./libft all
	$(CC) $(SRC) $(CFLAGS) $(MFLAGS) -L./mlx_opengl -lm -L./mlx_mms -lmlx $(MLX_FLAGS) $(LIBFT) -o $(TARGET)

clean :
	rm -rf $(OBJ)
	cd ./mlx_mms && make clean
	cd ./mlx_opengl && make clean
	cd ./libft && make fclean

fclean : clean
	rm -rf $(TARGET)
	rm -rf ./mlx_mms/libmlx.dylib
	rm -rf libm.a
	rm -rf so_long.dSYM

re : fclean all
