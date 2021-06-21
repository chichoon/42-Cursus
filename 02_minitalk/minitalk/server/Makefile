# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 22:28:37 by jiychoi           #+#    #+#              #
#    Updated: 2021/06/21 22:31:38 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MFLAGS		=	-g3 -fsanitize=address
SRCS		=	minitalk_server.c
OBJS		=	$(SRCS:.c=.o)
LIBFT		=	-L ../libft -lft
NAME		=	minitalk_server

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I ./

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
