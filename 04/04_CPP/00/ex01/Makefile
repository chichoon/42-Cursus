# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 15:14:47 by jiychoi           #+#    #+#              #
#    Updated: 2022/05/06 15:33:03 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	g++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	PhoneBook.cpp Contact.cpp main.cpp
OBJS	=	$(SRCS:.cpp=.o)
TARGET	=	phonebook
SUBJECT	=	00

LF			=	\e[1K\r$(NO_COLOR)
CRLF		=	\n$(LF)

all : $(TARGET)

$(TARGET) : $(OBJS)
	@printf "$(LF)CPP MODULE $(SUBJECT): $(TARGET)\n"
	@$(CC) $(OBJS) $(CFLAGS) -o $(TARGET)

%.o : %.cpp
	@$(CC) $(CFLAGS) -c -o $@ $< -I ./

clean :
	@printf "$(LF)Deleting $(TARGET)...\n"
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(TARGET)

re : fclean all
