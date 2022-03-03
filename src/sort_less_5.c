/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 02:45:28 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/03 01:11:38 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	ft_sort_3_2(int first, int second, int last, t_stack **a)
{
	if (first > second && second < last && last < first)
	{
		*a = ft_rotate(*a);
		ft_putstr_fd("ra\n", 1);
	}
	if (first < second && second > last && last > first)
	{
		ft_swap(*a);
		*a = ft_rotate(*a);
		ft_putstr_fd("sa\nra\n", 1);
	}
	if (first < second && second > last && last < first)
	{
		*a = ft_reverse_rotate(*a);
		ft_putstr_fd("rra\n", 1);
	}
}

void	ft_sort_3(t_stack **a)
{
	int	first;
	int	second;
	int	last;

	last = (*a)->next->next->value;
	second = (*a)->next->value;
	first = (*a)->value;
	if (first > second && second < last && last > first)
	{
		ft_swap(*a);
		ft_putstr_fd("sa\n", 1);
	}
	if (first > second && second > last && last < second)
	{
		ft_swap(*a);
		*a = ft_reverse_rotate(*a);
		ft_putstr_fd("sa\nrra\n", 1);
	}
	ft_sort_3_2(first, second, last, a);
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
	if (stack_b->index_sort < stack_b->next->index_sort)
	{
		ft_swap(stack_b);
		ft_putstr_fd("sb\n", 1);
	}
	ft_push(&stack_b, stack_a);
	ft_push(&stack_b, stack_a);
	ft_putstr_fd("pa\npa\n", 1);
}
