# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 22:28:37 by jiychoi           #+#    #+#              #
#    Updated: 2021/06/28 16:27:59 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MFLAGS		=	-g3 -fsanitize=address
SRCS		=	minitalk_server.c minitalk_server_getbyte.c
SRCS_BONUS	=	minitalk_server_bonus.c minitalk_server_getbyte_bonus.c
OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)
LIBFT		=	-L ../libft -lft
NAME		=	server
LF			=	\e[1K\r
CRLF		=	\n$(LF)

ifdef IF_BONUS
	OBJECTS = $(OBJS_BONUS)
else
	OBJECTS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJECTS)
	@printf "$(LF)Making Server...\n"
	@$(CC) $(OBJECTS) $(CFLAGS) $(LIBFT) -o $(NAME)

bonus :
	@$(MAKE) IF_BONUS=1 all

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $< -I ./

clean :
	@printf "$(LF)Deleting Server...\n"
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
