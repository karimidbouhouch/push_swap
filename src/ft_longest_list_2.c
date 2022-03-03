/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longest_list_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:19:47 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 03:46:36 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	get_longest_list(int *tab, int i, int count, int size)
{
	int	j;
	int	tmp;
	int	num;

	tmp = tab[i];
	num = tmp;
	j = i + 1;
	while (j <= size)
	{
		if (j == size)
			j = 0;
		if (tmp < tab[j])
		{
			tmp = tab[j];
			count++;
		}
		if (num == tab[j])
			break ;
		else if (j == size - 1)
			j = -1;
		j++;
	}
	return (count);
}

int	get_number_list_longer(t_stack **stack_a)
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
	return (number);
}

void	ft_push_longest_to_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;
	int		size;

	ft_longest_list(a, ft_stacksize(*a));
	tmp = *a;
	i = 0;
	size = ft_stacksize(*a) - ft_get_count_list_longer(a);
	while (i < size)
	{
		if (tmp->pushtob == 0)
		{
			ft_push(a, b);
			ft_putstr_fd("pb\n", 1);
			tmp = *a;
			i++;
		}
		else if (tmp->pushtob == 1)
		{
			*a = ft_rotate(*a);
			ft_putstr_fd("ra\n", 1);
			tmp = *a;
		}
	}
}

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
