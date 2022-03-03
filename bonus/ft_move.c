/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:12:49 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/03 01:31:56 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*ft_stack_before_last(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	while (stack->next)
	{
		tmp = stack;
		stack = stack->next;
	}
	return (tmp);
}

void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (ft_stacksize(stack) <= 2)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

t_stack	*ft_reverse_rotate(t_stack *stack)
{
	t_stack	*last;

	if (ft_stacksize(stack) <= 1)
		return (stack);
	last = ft_stacklast(stack);
	ft_stack_before_last(stack)->next = NULL;
	ft_stackadd_front(&stack, last);
	return (last);
}

t_stack	*ft_rotate(t_stack *stack)
{
	t_stack	*head;

	if (ft_stacksize(stack) <= 1)
		return (stack);
	head = stack->next;
	stack->next = NULL;
	ft_stackadd_back(&head, stack);
	return (head);
}

void	ft_push(t_stack **a, t_stack **b)
{
	t_stack	*new;
	t_stack	*tmp;

	tmp = *a;
	new = ft_stacknew((*a)->value, (*a)->index_sort);
	ft_stackadd_front(b, new);
	(*a) = (*a)->next;
	free(tmp);
}
