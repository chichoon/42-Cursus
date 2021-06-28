# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 22:28:35 by jiychoi           #+#    #+#              #
#    Updated: 2021/06/28 12:09:44 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MFLAGS		=	-g3 -fsanitize=address
SRCS		=	minitalk_client.c minitalk_client_sendbyte.c
OBJS		=	$(SRCS:.c=.o)
LIBFT		=	-L ../libft -lft
NAME		=	minitalk_client
LF			=	\e[1K\r$(NO_COLOR)
CRLF		=	\n$(LF)
NO_COLOR	=	\e[0m

all : $(NAME)

$(NAME) : $(OBJS)
	@printf "$(LF)Making Client...\n"
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $< -I ./

clean :
	@printf "$(LF)Deleting Client...\n"
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
