# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 11:48:15 by jiychoi           #+#    #+#              #
#    Updated: 2021/08/09 23:04:14 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MFLAGS		=	-g3 -fsanitize=address
SRCS		=	philo_main.c philo_init_struct.c\
				philo_thread_func.c\
				philo_utils_1.c philo_utils_2.c
#SRCS_BONUS	=
OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

CL_BOLD		=	\e[1m
CL_DIM		=	\e[2m
CL_UDLINE	=	\e[4m
NO_COLOR	=	\e[0m
LF			=	\e[1K\r$(NO_COLOR)
CRLF		=	\n$(LF)

ifdef IF_BONUS
	OBJECTS	=	$(OBJS_BONUS)
	TARGET	=	philo_bonus
	PRINT	=	Bonus
else
	OBJECTS	=	$(OBJS)
	TARGET	=	philo
	PRINT	=	Mandatory
endif

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	@printf "$(LF)🧙 Philosophers $(PRINT)\n"
	@$(CC) $(OBJECTS) $(CFLAGS) -o $(TARGET)

bonus :
	@$(MAKE) IF_BONUS=1 all

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $< -I ./

clean :
	@printf "$(LF)Deleting philo...\n"
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)

fclean : clean
	@rm -rf philo philo_bonus
