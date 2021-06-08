# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 14:50:22 by jiychoi           #+#    #+#              #
#    Updated: 2021/06/08 15:05:54 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
PARAM		=	-Wall -Wextra -Werror
GNL			=	./gnl/get_next_line_utils.c ./gnl/get_next_line.c
SRCS		=	$(GNL)
NAME		=	so_long

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I ./

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(TARGET)

re : fclean all
