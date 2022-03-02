/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:56:10 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 02:40:16 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_withspace(char *argv)
{
	t_stack	*send;
	char	**all;
	int		i;

	i = -1;
	send = NULL;
	all = ft_split(argv, ' ');
	if (check_digit(all))
		send = ft_fill_stack(all);
	while (all[++i])
		free(all[i]);
	free (all);
	return (send);
}

void	push_swap(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	check_same_number(stack_a);
	ft_fill_indexes(stack_a);
	if (!ft_is_sorted(stack_a))
	{
		if (ft_stacksize(stack_a) == 3)
			ft_sort_3(&stack_a);
		else if (ft_stacksize(stack_a) == 5)
			ft_sort_5(&stack_a);
		else
			ft_sorting(&stack_a, &stack_b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (ac > 1)
	{
		if (ac == 2)
		{
			if (ft_strchr(av[1], ' '))
				stack_a = ft_withspace(av[1]);
			else if (check_digit(&av[1]))
				stack_a = ft_fill_stack(&av[1]);
		}
		else if (check_digit(&av[1]))
			stack_a = ft_fill_stack(&av[1]);
		push_swap(stack_a);
	}
	else
		ft_putstr_fd("error\n", 1);
}
