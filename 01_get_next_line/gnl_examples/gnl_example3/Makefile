CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
NAME			= libgnl.a
SRC				= \
					get_next_line.c\
					get_next_line_utils.c
OBJ				= $(SRC:.c=.o)

%.o : %.c
	$(CC) -c $(CFLAGS) $? -o $@

$(NAME) : $(OBJ)
	ar src $@ $?

.PHONY: all clean fclean re

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
