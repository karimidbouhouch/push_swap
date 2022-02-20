NAME = push_swap
INC = push_swap.h
SRC = ft_move.c ft_stack.c push_swap.c sort_less_5.c
CFLAGS = -Wall -Werror -Wextra
all: $(NAME)
$(NAME): $(SRC:.c=.o)
	(cd libft; make bonus;)
	gcc $(CFLAGS) libft/libft.a $(SRC) -I $(INC) -o $(NAME)
clean: 
	(cd libft; make all;)
	rm -rf $(SRC:.c=.o)
fclean: clean
	(cd libft; make fclean;)
	rm -rf $(NAME)
re: fclean all