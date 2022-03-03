NAME = push_swap
bonus = checker
INC_BONUS = bonus/push_swap_bonus.h
INC = src/push_swap.h
SRC = 	src/ft_move.c \
		src/ft_stack.c \
		src/push_swap.c \
		src/sort_less_5.c \
		src/ft_longest_list.c \
		src/ft_longest_list_2.c\
		src/ft_sort_tab.c \
		src/ft_bestmove.c \
		src/ft_moving_to_a.c \
		src/ft_sorting.c \
		src/ft_bestmove2.c \
		src/ft_moving_to_a_2.c \
		src/ft_check_digit.c
SRC_BONUS = bonus/main.c \
			bonus/ft_stack.c \
			bonus/ft_move.c \
			bonus/ft_check_digit.c \
			bonus/ft_checker.c \
			bonus/get_next_line/get_next_line.c \
			bonus/get_next_line/get_next_line_utils.c
CFLAGS = -Wall -Werror -Wextra
all: $(NAME)
$(NAME): $(SRC:.c=.o)
	(cd libft; make all;)
	gcc $(CFLAGS) libft/libft.a $(SRC) -I $(INC) -o $(NAME)

bonus : $(INC_BONUS) $(SRC_BONUS:.c=.o)
	(cd libft; make all;)
	gcc $(CFLAGS) libft/libft.a $(SRC_BONUS) -I $(INC_BONUS) -o $(bonus)

clean: 
	(cd libft; make clean;)
	rm -rf $(SRC:.c=.o) $(SRC_BONUS:.c=.o)

fclean: clean
	(cd libft; make fclean;)
	rm -rf $(NAME) $(bonus)

re: fclean all