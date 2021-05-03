# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 15:47:50 by jiychoi           #+#    #+#              #
#    Updated: 2021/05/03 16:40:16 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
PARAM		= -Wall -Wextra -Werror
SRCS		= $(wildcard *.c)
OBJS		= $(SRCS:.c=.o)
TARGET		= libft.a

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar -rc $(TARGET) $(OBJS)

%.o : %.c
	$(CC) $(PARAM) -c -o $@ $< -I libft.h

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

