# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/30 23:46:55 by jiychoi           #+#    #+#              #
#    Updated: 2021/07/19 00:04:42 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MFLAGS		=	-g3 -fsanitize=address
SRCS		=	srcs/push_swap_linked_list_1.c srcs/push_swap_linked_list_2.c\
				srcs/push_swap_init_stack.c srcs/push_swap_init_stack_2.c\
				srcs/push_swap_main.c srcs/push_swap_utils.c\
				srcs/push_swap_find_pivot.c srcs/push_swap_cmd.c\
				srcs/push_swap_operate.c srcs/push_swap_optimize.c\
				srcs/push_swap_operate_small_1.c srcs/push_swap_operate_small_2.c\
				srcs/push_swap_operate_small_3.c
SRCS_BONUS	=	gnl/get_next_line.c gnl/get_next_line_utils.c\
				bns/push_swap_main_bonus.c bns/push_swap_utils_bonus.c\
				bns/push_swap_linked_list_1_bonus.c bns/push_swap_linked_list_2_bonus.c\
				bns/push_swap_init_stack_bonus.c\
				bns/push_swap_cmd_bonus.c bns/push_swap_cmd_2_bonus.c
OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)
LIBFT		=	-L ./libft -lft
LF			=	\e[1K\r$(NO_COLOR)
CRLF		=	\n$(LF)

ifdef IF_BONUS
	TARGET		= checker
	OBJECTS		= $(OBJS_BONUS)
	COMMENT 	= @printf "$(LF)🔄Push_Swap Checker\n"
else
	TARGET		= push_swap
	OBJECTS		= $(OBJS)
	COMMENT 	= @printf "$(LF)🔄Push_Swap\n"
endif

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(COMMENT)
	@$(MAKE) -C ./libft all
	@printf "$(LF)Compiling Main source...\n"
	@$(CC) $(OBJECTS) $(CFLAGS) $(MFLAGS) $(LIBFT) -o $(TARGET)

bonus :
	@$(MAKE) IF_BONUS=1 all

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $< -I ./

clean :
	@printf "$(LF)Deleting Object files...\n"
	@cd ./libft && make fclean
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)


fclean : clean
	@printf "$(LF)Deleting Compiled file...\n"
	@cd ./libft && rm -rf libft.a
	@rm -rf push_swap
	@rm -rf checker
	@rm -rf push_swap.dSYM
	@rm -rf checker.dSYM

re : fclean all
