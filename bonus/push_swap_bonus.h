/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 05:47:11 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/03 01:25:04 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index_sort;
	struct s_stack	*next;
}	t_stack;
int		check_digit(char **av);
t_stack	*ft_fill_stack(char **numbers);
t_stack	*ft_stacknew(int value, int index);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_swap(t_stack *stack);
t_stack	*ft_reverse_rotate(t_stack *stack);
t_stack	*ft_rotate(t_stack *stack);
void	ft_push(t_stack **a, t_stack **b);
int		ft_stacksize(t_stack *stack);
t_stack	*ft_stacklast(t_stack *lst);
void	ft_swap(t_stack *stack);
void	ft_checker(t_stack *a, t_stack *b);
int		ft_readline(t_stack **a, t_stack **b);
void	ft_free(t_stack **lst);
void	check_same_number(t_stack *stack);
#endif