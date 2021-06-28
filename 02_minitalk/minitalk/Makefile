# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 19:20:50 by jiychoi           #+#    #+#              #
#    Updated: 2021/06/28 16:28:33 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MFLAGS		=	-g3 -fsanitize=address
NAME		=	minitalk

all : $(NAME)

$(NAME) :
	@printf "$(LF)💬Minitalk\n"
	@$(MAKE) -C ./libft all
	@$(MAKE) -C ./client all
	@$(MAKE) -C ./server all


clean :
	@cd ./libft && make fclean
	@cd ./client && make clean
	@cd ./server && make clean

fclean : clean
	@cd ./client && rm -rf client
	@cd ./server && rm -rf server

bonus :
	@$(MAKE) -C ./libft all
	@$(MAKE) -C ./client bonus
	@$(MAKE) -C ./server bonus

re : fclean all
