# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 14:50:22 by jiychoi           #+#    #+#              #
#    Updated: 2021/07/19 19:46:22 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MFLAGS		=	-g3 -fsanitize=address
SRC			=	so_long_main.c so_long_utils.c so_long_parse_map.c \
				so_long_validate_map.c so_long_draw_screen.c\
				so_long_init_struct.c so_long_draw_assets.c\
				so_long_move_char.c so_long_handle_events.c\
				gnl/get_next_line.c gnl/get_next_line_utils.c
SRC_BONUS	=	so_long_main_bonus.c so_long_utils_bonus.c\
				so_long_parse_map_bonus.c so_long_draw_assets_2_bonus.c \
				so_long_validate_map_bonus.c so_long_draw_screen_bonus.c\
				so_long_init_struct_bonus.c so_long_draw_assets_bonus.c\
				so_long_move_char_bonus.c so_long_handle_events_bonus.c\
				gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ			=	$(SRC:.c=.o)
OBJ_BONUS	=	$(SRC_BONUS:.c=.o)
LIBFT		=	-L ./libft -lft
MLX_OPENGL	=	-L ./mlx_opengl -lmlx
MLX_FLAGS	=	-framework OpenGL -framework Appkit
TARGET		=	so_long

ifdef IF_BONUS
	OBJECTS = $(OBJ_BONUS)
else
	OBJECTS = $(OBJ)
endif

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	@$(MAKE) -C ./mlx_opengl all
	@$(MAKE) -C ./libft all
	$(CC) $(OBJECTS) $(CFLAGS) $(MLX_OPENGL) $(MLX_FLAGS) $(LIBFT) -o $(TARGET)

bonus :
	@$(MAKE) IF_BONUS=1 all

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I ./

clean :
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	cd ./mlx_opengl && make clean
	cd ./libft && make fclean

fclean : clean
	rm -rf $(TARGET)
	rm -rf libmlx.a
	rm -rf so_long.dSYM

re : fclean all
