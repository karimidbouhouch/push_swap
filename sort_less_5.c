/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 02:45:28 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 01:27:20 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack **stack)
{
	if (!ft_is_sorted(*stack) && (*stack)->value > (*stack)->next->value)
	{
		ft_swap(*stack);
		ft_putstr_fd("sa\n", 1);
	}
	if (!ft_is_sorted(*stack))
	{
		*stack = ft_reverse_rotate(*stack);
		ft_putstr_fd("rra\n", 1);
	}
	if ((*stack)->value > (*stack)->next->value)
	{
		ft_swap(*stack);
		ft_putstr_fd("sa\n", 1);
	}
}

void	ft_sort_5(t_stack **stack_a)
{
	t_stack	*stack_b;

	while (ft_stacksize(*stack_a) != 3)
	{
		if ((*stack_a)->index_sort < 2)
		{
			ft_push(stack_a, &stack_b);
			ft_putstr_fd("pb\n", 1);
		}
		else
		{
			*stack_a = ft_reverse_rotate(*stack_a);
			ft_putstr_fd("rra\n", 1);
		}
	}
	ft_sort_3(stack_a);
	if (stack_b->value < stack_b->next->value)
	{
		ft_swap(stack_b);
		ft_putstr_fd("sb\n", 1);
	}
	ft_push(&stack_b, stack_a);
	ft_push(&stack_b, stack_a);
	ft_putstr_fd("pa\npa\n", 1);
}
