/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bestmove2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 01:23:49 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 03:46:32 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	ft_countforstart(t_stack *start, int index)
{
	t_stack	*stmp;
	int		count;
	int		counting;

	counting = 0;
	count = 0;
	stmp = start;
	while (start)
	{
		counting++;
		if (index > start->index_sort)
			count = counting;
		else
			break ;
		start = start->next;
	}
	start = stmp;
	return (count);
}

int	ft_countforhead(t_stack *head, int index, int end)
{
	int		count;
	t_stack	*tmp;
	int		counting;

	tmp = head;
	counting = 0;
	count = 0;
	while (head && head->index_sort != end)
	{
		counting++;
		if (index > head->index_sort)
			count = counting;
		else
			break ;
		head = head->next;
	}
	head = tmp;
	return (count);
}

void	ft_first(int *total, int a, int b, t_stack *x)
{
	a = ft_optimize(a, ft_stacksize(x));
	b = b + 1;
	if (a > b)
		*total = a;
	else
		*total = b;
}

int	ft_second(t_global p, int b)
{
	int	total;
	int	a;

	a = ft_optimize(p.a, ft_stacksize(*p.stack_a));
	b = ft_optimize(b, ft_stacksize(*p.stack_b));
	if (a > b)
		total = a;
	else
		total = b;
	return (total);
}

int	ft_theelse(t_global corrent, int b)
{
	int	total;

	corrent.a = ft_optimize(ft_movementsfuture(*corrent.stack_a, corrent.b),
			ft_stacksize(*corrent.stack_a));
	b = ft_optimize(b, ft_stacksize(*corrent.stack_b));
	total = corrent.a + b;
	return (total);
}
