/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:57:16 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/02/25 21:59:00 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
	int	value;
	int index_sort;
	int	pushtob;
	int count;
	struct s_stack *next;
} t_stack;

typedef struct s_global
{
	int a;
	int b;
	struct s_stack **stack_a;
	struct s_stack **stack_b;
} t_global;

t_stack	*ft_rotate(t_stack *stack);
t_stack	*ft_reverse_rotate(t_stack *stack);
void	ft_swap(t_stack *stack);
void	ft_push(t_stack **a, t_stack **b);


t_stack	*ft_stack_before_last(t_stack *stack);
int 	ft_stacksize(t_stack *stack);
t_stack *ft_fill_stack(char **numbers);
t_stack	*ft_stacknew(int value, int index);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);
int	ft_is_sorted(t_stack *stack);


int	*ft_sort_tab(int *tab, int size);
int	*ft_fill_tab(t_stack *stack);
void	ft_fill_indexes(t_stack *stack);

void	ft_longest_list(t_stack **stack_a, int size);
void	ft_longest_list_2(t_stack **stack_a);
int	ft_get_number_list_longer(t_stack **stack_a);
void ft_insert_count_in_stack(t_stack *stack, int number, int count);
int	ft_get_count_list_longer(t_stack **stack_a);

void	ft_sort_2(t_stack **stack);
void	ft_sort_3(t_stack **stack);
void	ft_sort_4(t_stack **stack);
void	ft_sort_5(t_stack **stack);



int	ft_bestmovesindex(t_global push, int current_b);


#endif