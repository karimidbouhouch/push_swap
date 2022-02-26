/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 04:23:04 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/02/21 04:23:41 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
