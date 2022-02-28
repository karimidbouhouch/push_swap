NAME = push_swap
INC = push_swap.h
SRC = ft_move.c ft_stack.c push_swap.c sort_less_5.c ft_longest_list.c ft_sort_tab.c ft_bestmove.c ft_moving_to_a.c
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