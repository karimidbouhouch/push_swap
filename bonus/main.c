/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:56:10 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/03 01:42:48 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		if (ac == 2)
		{
			if (ft_strchr(av[1], ' '))
				a = ft_withspace(av[1]);
			else if (check_digit(&av[1]))
				a = ft_fill_stack(&av[1]);
		}
		else if (check_digit(&av[1]))
			a = ft_fill_stack(&av[1]);
		check_same_number(a);
		if (!ft_readline(&a, &b))
			return (0);
		ft_checker(a, b);
	}
}
