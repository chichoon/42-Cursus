# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 14:50:22 by jiychoi           #+#    #+#              #
#    Updated: 2021/06/13 07:56:17 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRC			=	main.c
OBJ			=	$(SRC:.c=.o)
MLX			=	./mlx -lmlx -framework OpenGL -framework Appkit
TARGET		=	so_long

all : $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I ./

$(TARGET) : $(OBJ)
	$(MAKE) -C ./mlx all
	$(CC) $(SRC) $(CFLAGS) $(MLX) -o $(TARGET)

clean :
	rm -rf $(OBJ)
	cd ./mlx clean

fclean : clean
	rm -rf $(TARGET)
	rm -rf ./mlx/libmlx.dylib

re : fclean all
