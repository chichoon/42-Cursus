# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 22:28:35 by jiychoi           #+#    #+#              #
#    Updated: 2021/07/26 18:07:15 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MFLAGS		=	-g3 -fsanitize=address
SRCS		=	minitalk_client.c
SRCS_BONUS	=	minitalk_client_bonus.c minitalk_client_sendbyte_bonus.c
OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)
LIBFT		=	-L ../libft -lft
NAME		=	client
LF			=	\e[1K\r$(NO_COLOR)
CRLF		=	\n$(LF)

ifdef IF_BONUS
	OBJECTS = $(OBJS_BONUS)
else
	OBJECTS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJECTS)
	@printf "$(LF)Making Client...\n"
	@$(CC) $(OBJECTS) $(CFLAGS) $(LIBFT) -o $(NAME)

bonus :
	@$(MAKE) IF_BONUS=1 all

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $< -I ./

clean :
	@printf "$(LF)Deleting Client...\n"
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
