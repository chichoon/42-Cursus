# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/30 23:46:55 by jiychoi           #+#    #+#              #
#    Updated: 2021/07/15 22:55:18 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MFLAGS		=	-g3 -fsanitize=address
SRCS		=	push_swap_linked_list_1.c push_swap_linked_list_2.c\
				push_swap_init_stack.c push_swap_main.c push_swap_utils.c\
				push_swap_find_pivot.c push_swap_cmd.c\
				push_swap_operate.c push_swap_operate_small_1.c push_swap_operate_small_2.c\
				push_swap_optimize.c
#SRCS_BONUS	=
OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)
LIBFT		=	-L ./libft -lft
NAME		=	push_swap
NAME_BONUS	=	checker
LF			=	\e[1K\r$(NO_COLOR)
CRLF		=	\n$(LF)

ifdef IF_BONUS
	OBJECTS = $(OBJS_BONUS)
	TARGET = $(NAME_BONUS)
	COMMENT = @printf "$(LF)🔄Push_Swap Checker\n"
else
	OBJECTS = $(OBJS)
	TARGET = $(NAME)
	COMMENT = @printf "$(LF)🔄Push_Swap\n"
endif

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(COMMENT)
	@$(MAKE) -C ./libft all
	@printf "$(LF)Compiling Target...\n"
	@$(CC) $(OBJECTS) $(CFLAGS) $(MFLAGS) $(LIBFT) -o $(TARGET)

bonus : @(MAKE) IF_BONUS=1 all

%.o : %.c
	@$(CC) $(CFLAGS) $(MFLAGS) -c -o $@ $< -I ./

clean :
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)
	cd ./libft && make fclean

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	rm -rf $(NAME).dSYM $(NAME_BONUS).dSYM

re : fclean all
