NAME = bsq
SRC = *.c
OBJECT = *.o
all : $(NAME)
$(NAME): functions.h utils1.h utils2.h
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc $(OBJECT) -o $(NAME)
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
