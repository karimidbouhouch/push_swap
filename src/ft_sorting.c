/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 01:27:56 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 03:46:51 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

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

int	ft_optimize(int moves, int count)
{
	if (moves > count / 2)
		return (count - moves);
	return (moves);
}

int	ft_ismidel(int *moves, int size)
{
	int	x;

	x = size / 2;
	if (size % 2 == 0 && x == *moves)
		return (*moves);
	else if (size % 2 == 1 && x == *moves)
	{
		(*moves)++;
		return (*moves);
	}
	return (-1);
}

void	ft_last_sort(t_stack *stack_a, int count)
{
	t_stack	*tmp;

	tmp = stack_a;
	if (count != ft_optimize(count, ft_stacksize(tmp)))
	{
		count = ft_optimize(count, ft_stacksize(tmp));
		while (count)
		{
			tmp = ft_reverse_rotate(tmp);
			ft_putstr_fd("rra\n", 1);
			count--;
		}
	}
	else
	{
		while (count)
		{
			tmp = ft_rotate(tmp);
			ft_putstr_fd("ra\n", 1);
			count--;
		}
	}
}

void	ft_sorting(t_stack **a, t_stack **b)
{
	t_global	push;
	t_stack		*tmp;
	int			count;

	push.stack_a = a;
	push.stack_b = b;
	ft_push_longest_to_b(a, b);
	while (ft_stacksize(*b))
	{
		push.a = ft_getbestmoveindex(push, 0);
		ft_move_to_a(a, b, push.a);
	}
	count = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->index_sort == 0)
			break ;
		count++;
		tmp = tmp->next;
	}
	tmp = *a;
	ft_last_sort(*a, count);
	ft_free(a);
}
