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

CC			=	gcc
PARAM		=	-Wall -Wextra -Werror
SRCS		=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
				ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
				ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
				ft_calloc.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS_BNS	=	ft_lstnew.c
OBJS		=	$(SRCS:.c=.o)
OBJS_BNS	=	$(SRCS_BNS:.c=.o)
NAME		=	libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(PARAM) -c -o $@ $< -I libft.h

clean :
	rm -f $(OBJS) $(OBJS_BNS)

fclean : clean
	rm -f $(NAME)

bonus : $(OBJS) $(OBJS_BNS)
	ar -rc $(NAME) $^

re : fclean all

