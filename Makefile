NAME = bsq
SRC = *.c
OBJ = $(SRC:.c=.o)
all : $(NAME)
$(NAME): functions.h
    gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)
fclean: clean
    rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
