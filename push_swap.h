/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:57:16 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/02/15 23:16:34 by kid-bouh         ###   ########.fr       */
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
	struct s_stack *next;
} t_stack;


t_stack	*ft_rotate(t_stack *stack);
t_stack	*ft_reverse_rotate(t_stack *stack);
void	ft_swap(t_stack *stack);


t_stack	*ft_stack_before_last(t_stack *stack);
int 	ft_stacksize(t_stack *stack);
t_stack *ft_fill_stack(char **numbers);
t_stack	*ft_stacknew(int value);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);


#endif