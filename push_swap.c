/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:56:10 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/02/25 22:02:21 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(int ac, char **av)
{
	int	i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
				j++;
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int check_same_number2(int *numbers, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (numbers[i] == numbers[index])
			return (1);
		i++;
	}
	return (0);
}

void	check_same_number(int *numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		if (check_same_number2(numbers, i))
		{
			ft_putstr_fd("error ! same value", 1);
			return ;
		}
		i++;
	}
}

void	ft_push_longest_to_b(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	int i;
	int size;

	ft_longest_list(a, ft_stacksize(*a));
	tmp = *a;
	i = 0;
	size = ft_stacksize(*a) - ft_get_count_list_longer(a);
	while (i < size)
	{
		if (tmp->pushtob == 0)
		{
			ft_push(a,b);
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

void	ft_sort(t_stack **a, t_stack **b)
{
	t_global push;
	int	i;
	
	i = 0;
	push.stack_a = a;
	push.stack_b = b;
	ft_push_longest_to_b(a, b);
	// while (ft_stacksize(*b))
	// {
		push.a = ft_bestmovesindex(push, i);
		printf("[index best move = %d]\n",push.a);
	// }
}

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	if (ac > 1)
	{
		if (check_digit(ac, av) == 0)
			ft_putstr_fd("error", 1);
		else
		{
			stack_a = ft_fill_stack(av);
			ft_fill_indexes(stack_a);
			
			if (!ft_is_sorted(stack_a))
			{
				if (ft_stacksize(stack_a) == 3)
					ft_sort_3(&stack_a);
				else if (ft_stacksize(stack_a) == 2)
					ft_sort_2(&stack_a);
				else if (ft_stacksize(stack_a) == 5)
					ft_sort_5(&stack_a);
				else if (ft_stacksize(stack_a) == 4)
					ft_sort_4(&stack_a);	
				else
					ft_sort(&stack_a, &stack_b);
			}
			printf("------\n");
			while (stack_a)
			{
				printf("%d => %d\n",stack_a->value,stack_a->index_sort);
				stack_a = stack_a->next;
			}
			printf("------\n");
			while (stack_b)
			{
				printf("%d => %d\n",stack_b->value,stack_b->index_sort);
				stack_b = stack_b->next;
			}
		}
	}
}
