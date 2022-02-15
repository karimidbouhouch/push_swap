/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:56:10 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/02/15 23:40:06 by kid-bouh         ###   ########.fr       */
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

void	ft_sort_3(t_stack *stack)
{
	int	first;
	int second;
	int	last;

	first = stack->value;
	second = stack->next->value;
	last = stack->next->next->value;
	if (first > second && second < last && last > first)
	{
		ft_swap(stack);
		ft_putstr_fd("sa\n", 1);
	}
	if (first > second && second > last)
	{
		// ft_swap(stack);
		ft_reverse_rotate(stack);
	}
	// if (first > second && second < last)
	// {
	// 	ft_rotate(stack);
	// 	ft_putstr_fd("ra\n", 1);
	// }
}

int	main(int ac, char **av)
{
	t_stack *stack;

	if (ac > 1)
	{
		if(check_digit(ac, av) == 0)
			ft_putstr_fd("is not digit", 1);
		else
		{
			stack = ft_fill_stack(av);
			ft_rotate(stack);
			// ft_sort_3(stack);
			// while (stack)
			// {
			// 	printf("%d\n",stack->value);
			// 	stack = stack->next;
			// }
		}
	}
}
