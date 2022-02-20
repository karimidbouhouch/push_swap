/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:56:10 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/02/21 00:57:13 by kid-bouh         ###   ########.fr       */
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

int	*ft_sort_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	*ft_fill_tab(t_stack *stack)
{
	int	*numbers;
	int	i;
	int size;

	i = 0;
	size = ft_stacksize(stack);
	numbers = malloc(sizeof(int) * size);
	if(!numbers)
		return (NULL);
	while (stack)
	{
		numbers[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (numbers);
}

void	ft_fill_indexes(t_stack *stack)
{
	t_stack *tmp;
	int *tab;
	int	size;
	int	i;

	i = 0;
	tmp = stack;
	size = ft_stacksize(stack);
	tab = ft_sort_tab(ft_fill_tab(stack), size);
	while (i < size)
	{
		while (tmp)
		{
			if (tab[i] == tmp->value)
			{
				tmp->index_sort = i;
			}
			tmp = tmp->next;
		}
		tmp = stack;
		i++;
	}
}


int	ft_is_sorted(t_stack *stack)
{
	t_stack *tmp;
	int	number;
	
	number = stack->value;
	tmp = stack->next;
	while (tmp)
	{
		if (number > tmp->value)
			return (0);
		if (number < tmp->value)
			number = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}

int	ft_put_push(t_stack **stack_a)
{
	t_stack *tmp;
	int number;
	int count;
	
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
	return(number);
}

void	ft_list_longer(t_stack **stack_a)
{
	int	*tab;
	int size;
	int	i;
	int j;
	int count;
	int tmp;
	int num;
	t_stack *tmp_stack;

	tab = ft_fill_tab(*stack_a);
	size = ft_stacksize(*stack_a);
	i = 0;
	count = 1;
	while (i < size)
	{
		tmp = tab[i];
		num = tmp;
		j = i + 1;
		while (j <= size)
		{
			if (tmp < tab[j])
			{
				tmp = tab[j];
				count++;
			}
			if (j == size)
				j = -1;
			else if (num == tab[j])
				break ;
			if (j == size - 1)
				j = -1;
			j++;
		}
		tmp_stack = *stack_a;
		while (tmp_stack)
		{
			if (tmp_stack->value == tab[i])
				tmp_stack->count = count;
			tmp_stack = tmp_stack->next;
		}
		count = 1;
		i++;
	}
	i = ft_put_push(stack_a);
	printf("\n---- %d ----\n",i);
}

void	ft_sort(t_stack **stack_a)
{
	ft_list_longer(stack_a);
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
			if(!ft_is_sorted(stack_a))
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
					ft_sort(&stack_a);
			}
			while (stack_a)
			{
				printf("%d => %d\n",stack_a->value,stack_a->count);
				stack_a = stack_a->next;
			}
		}
	}
}
