/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 02:39:57 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/03 01:41:31 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		(*lst) = (*lst)->next;
		free(tmp);
	}
}

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
			{
				ft_putstr_fd("error", 1);
				exit(1);
			}
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
			exit(0);
		}
		stack = stack->next;
	}
}

t_stack	*ft_stacklast(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}
