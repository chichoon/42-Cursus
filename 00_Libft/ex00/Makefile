# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 15:47:50 by jiychoi           #+#    #+#              #
#    Updated: 2021/05/03 15:51:28 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
PARAM		= -Wall -Wextra -Werror
DIR			= src
SRCS		= $(DIR)/*.c
OBJS		= $(SRCS:.c=.o)
TARGET		= libft.a
INC			= -I includes

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar -rc $(TARGET) $^

%.o : %.c
	$(CC) $(PARAM) -c -o $@ $< $(INC)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

