# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 17:17:23 by jiychoi           #+#    #+#              #
#    Updated: 2021/05/20 13:15:33 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
PARAM		=	-Wall -Wextra -Werror
SRCS		=	ft_printf_printing1.c ft_printf_printing2.c ft_printf_printing3.c \
				ft_printf_utils1.c ft_printf_utils2.c ft_printf_utils3.c \
				ft_printf_params_1.c ft_printf_params_2.c \
				ft_printf_fmt.c ft_printf.c
OBJS		=	$(SRCS:.c=.o)
NAME		=	libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(PARAM) -c -o $@ $< -I printft.h

clean :
	rm -f $(OBJS) $(OBJS_BNS)

fclean : clean
	rm -f $(NAME)

bonus : $(OBJS) $(OBJS_BNS)
	ar -rc $(NAME) $^

re : fclean all

.PHONY : all clean fclean re
