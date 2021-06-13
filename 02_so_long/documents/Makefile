# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 14:50:22 by jiychoi           #+#    #+#              #
#    Updated: 2021/06/13 08:35:02 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MFLAGS		=	-g3 -fsanitize=address
SRC			=	main.c
OBJ			=	$(SRC:.c=.o)
MLX			=	-L ./mlx -lmlx -framework OpenGL -framework Appkit
TARGET		=	so_long

all : $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I ./

$(TARGET) : $(OBJ)
	$(MAKE) -C ./mlx all
	cd ./mlx && cp libmlx.dylib ../
	$(CC) $(SRC) $(CFLAGS) $(MFLAGS) $(MLX) -o $(TARGET)

clean :
	rm -rf $(OBJ)
	rm -rf libmlx.dylib
	cd ./mlx && make clean

fclean : clean
	rm -rf $(TARGET)
	rm -rf ./mlx/libmlx.dylib

re : fclean all
