# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/30 23:46:55 by jiychoi           #+#    #+#              #
#    Updated: 2021/07/01 20:58:49 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MFLAGS		=	-g3 -fsanitize=address
SRCS		=	push_swap_linked_list.c\
				push_swap_cmd_s.c push_swap_cmd_p.c push_swap_cmd_r.c push_swap_cmd_rr.c\
SRCS_BONUS	=
OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)
LIBFT		=	-L ../libft -lft
NAME		=	push_swap
NAME_BONUS	=	checker
LF			=	\e[1K\r$(NO_COLOR)
CRLF		=	\n$(LF)

all : $(NAME)

$(NAME) : $(OBJS)
	@printf "$(LF)🔄Push_Swap\n"
	@printf "$(LF)Making Libft...\n"
	@$(MAKE) -C ./libft all


bonus : $(NAME_BONUS)

