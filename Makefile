SRC	=	$(shell echo src/*.c)

OBJ 	= 	$(SRC:.c=.o)

NAME	= 	matchstick

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
