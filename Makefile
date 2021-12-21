NAME = bsq
SRC = main.c utils1.c
OBJ = $(SRC:.c=.o)
all : $(NAME)
$(NAME): functions.h
    gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)
clean:
    rm -f $(OBJ)
fclean: clean
    rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
