# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 22:28:37 by jiychoi           #+#    #+#              #
#    Updated: 2021/06/28 12:09:56 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MFLAGS		=	-g3 -fsanitize=address
SRCS		=	minitalk_server.c minitalk_server_getbyte.c
OBJS		=	$(SRCS:.c=.o)
LIBFT		=	-L ../libft -lft
NAME		=	minitalk_server
LF			=	\e[1K\r
CRLF		=	\n$(LF)

all : $(NAME)

$(NAME) : $(OBJS)
	@printf "$(LF)Making Server...\n"
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $< -I ./

clean :
	@printf "$(LF)Deleting Server...\n"
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
