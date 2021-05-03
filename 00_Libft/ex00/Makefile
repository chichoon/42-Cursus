# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 15:47:50 by jiychoi           #+#    #+#              #
#    Updated: 2021/05/03 16:31:48 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
PARAM		= -Wall -Wextra -Werror
DIR			= src
SRCS		= $($(DIR)/%.c)
OBJS		= $($(DIR)SRCS:.c=.o)
TARGET		= libft.a
INC			= -I ./

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(OBJS)
	ar -rc $(TARGET) $<

$($(DIR)/%.o) : $($(DIR)/%.c)
	$(CC) $(PARAM) -c -o $@ $< $(INC)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

