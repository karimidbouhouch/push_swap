/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:12:49 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/02/22 01:11:27 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	int tmp;

	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

t_stack	*ft_reverse_rotate(t_stack *stack)
{
	t_stack *last;

	last = ft_stacklast(stack);
	ft_stack_before_last(stack)->next = NULL;
	ft_stackadd_front(&stack, last);
	return (last);
}

t_stack	*ft_rotate(t_stack *stack)
{
	t_stack *head;

	head = stack->next;
	stack->next = NULL;
	ft_stackadd_back(&head, stack);
	return (head);
}

void	ft_push(t_stack **a, t_stack **b)
{
	t_stack *new;
	t_stack *tmp;

	tmp = *a;
	new = ft_stacknew((*a)->value,(*a)->index_sort);
	ft_stackadd_front(b, new);
	(*a) = (*a)->next;
}