/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 02:39:57 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 02:40:23 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_same_number2(int number, t_stack *s)
{
	t_stack	*tmp;

	tmp = s->next;
	while (tmp)
	{
		if (number == tmp->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	check_same_number(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (stack)
	{
		if (check_same_number2(stack->value, stack))
		{
			ft_putstr_fd("error\n", 1);
			exit(1);
		}
		stack = stack->next;
	}
}
