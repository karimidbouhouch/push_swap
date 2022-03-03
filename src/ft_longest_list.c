/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longest_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 04:21:14 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 03:46:38 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	ft_get_count_list_longer(t_stack **stack_a)
{
	t_stack	*tmp;
	int		number;
	int		count;

	number = (*stack_a)->value;
	count = (*stack_a)->count;
	tmp = (*stack_a)->next;
	while (tmp)
	{
		if (count < tmp->count)
		{
			count = tmp->count;
			number = tmp->value;
		}
		tmp = tmp->next;
	}
	return (count);
}

void	ft_longest_list_3(t_stack **stack_a, int num, int tmp)
{
	t_stack	*tmp_stack;

	tmp_stack = *stack_a;
	while (tmp_stack)
	{
		if (num == tmp_stack->value)
			break ;
		else if (tmp < tmp_stack->value)
		{
			tmp = tmp_stack->value;
			tmp_stack->pushtob = 1;
		}
		tmp_stack = tmp_stack->next;
	}
}

void	ft_longest_list_2(t_stack **stack_a)
{
	t_stack	*tmp_stack;
	int		num;
	int		i;
	int		tmp;

	i = 0;
	num = get_number_list_longer(stack_a);
	tmp_stack = *stack_a;
	while (tmp_stack)
	{
		if (num == tmp_stack->value && i == 0)
		{
			tmp_stack->pushtob = 1;
			tmp = num;
			i = 1;
		}
		else if (tmp < tmp_stack->value && i == 1)
		{
			tmp = tmp_stack->value;
			tmp_stack->pushtob = 1;
		}
		tmp_stack = tmp_stack->next;
	}
	ft_longest_list_3(stack_a, num, tmp);
}

void	insert_count_in_stack(t_stack *stack, int number, int count)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value == number)
			tmp->count = count;
		tmp = tmp->next;
	}
}

void	ft_longest_list(t_stack **stack_a, int size)
{
	int	*tab;
	int	i;
	int	count;

	tab = ft_fill_tab(*stack_a);
	i = 0;
	count = 1;
	while (i < size)
	{
		count = get_longest_list(tab, i, count, size);
		insert_count_in_stack(*stack_a, tab[i], count);
		count = 1;
		i++;
	}
	free(tab);
	ft_longest_list_2(stack_a);
}
