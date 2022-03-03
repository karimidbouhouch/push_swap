/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:57:16 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 22:51:56 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index_sort;
	int				pushtob;
	int				count;
	struct s_stack	*next;
}	t_stack;

typedef struct s_global
{
	int				a;
	int				b;
	int				tmp_a;
	int				tmp_b;
	struct s_stack	**stack_a;
	struct s_stack	**stack_b;
}	t_global;

t_stack	*ft_rotate(t_stack *stack);
t_stack	*ft_reverse_rotate(t_stack *stack);
void	ft_swap(t_stack *stack);
void	ft_push(t_stack **a, t_stack **b);
t_stack	*ft_stack_before_last(t_stack *stack);
int		ft_stacksize(t_stack *stack);
t_stack	*ft_fill_stack(char **numbers);
t_stack	*ft_stacknew(int value, int index);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);
int		ft_is_sorted(t_stack *stack);
int		*ft_sort_tab(int *tab, int size);
int		*ft_fill_tab(t_stack *stack);
void	ft_fill_indexes(t_stack *stack);
void	ft_longest_list(t_stack **stack_a, int size);
int		get_longest_list(int *tab, int i, int count, int size);
int		get_number_list_longer(t_stack **stack_a);
int		ft_get_count_list_longer(t_stack **stack_a);
void	ft_sort_3(t_stack **stack);
void	ft_sort_5(t_stack **stack);
int		ft_getbestmoveindex(t_global push, int b);
int		ft_movementsfuture(t_stack *a, int current_b);
int		ft_optimize(int moves, int count);
int		ft_ismidel(int *moves, int size);
void	ft_move_to_a(t_stack **a, t_stack **b, int index);
void	ft_sorting(t_stack **a, t_stack **b);
void	ft_last_sort(t_stack *stack_a, int count);
int		ft_countforstart(t_stack *start, int index);
int		ft_countforhead(t_stack *head, int index, int end);
void	ft_first(int *total, int a, int b, t_stack *x);
int		ft_second(t_global p, int b);
int		ft_theelse(t_global corrent, int b);
void	ft_push_longest_to_b(t_stack **a, t_stack **b);
void	ft_rrr_rra_rrb(t_stack **a, t_stack **b, int amoves, int bmoves);
void	ft_rra_rb(t_stack **a, t_stack **b, int amoves, int bmoves);
void	ft_rr_ra_rb(t_stack **a, t_stack **b, int amoves, int bmoves);
void	ft_rrb_ra(t_stack **a, t_stack **b, int amoves, int bmoves);
int		check_digit(char **av);
void	check_same_number(t_stack *stack);
void	ft_free(t_stack **lst);
#endif