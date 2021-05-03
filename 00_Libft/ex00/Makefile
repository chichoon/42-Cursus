# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 15:47:50 by jiychoi           #+#    #+#              #
#    Updated: 2021/05/03 20:42:41 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
PARAM		= -Wall -Wextra -Werror
SRCS		= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_calloc.c ft_strdup.c
OBJS		= $(SRCS:.c=.o)
NAME		= libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(PARAM) -c -o $@ $< -I libft.h

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

