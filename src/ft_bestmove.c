/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bestmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:13:23 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 03:46:26 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	ft_count(t_stack *head, t_stack *start, int index)
{
	int	count;
	int	startindex;

	count = 0;
	startindex = start->index_sort;
	if (head != start)
	{
		count = ft_countforstart(start, index);
		startindex = ft_countforhead(head, index, startindex);
		if (count < ft_stacksize(start))
			return (count + (ft_stacksize(head) - ft_stacksize(start)));
		else
			return (startindex);
	}
	else
		count = ft_countforstart(start, index);
	return (count);
}

int	ft_movementsfuture(t_stack *a, int current_b)
{
	t_stack	*head;
	t_stack	*start;
	int		index;
	int		count;

	head = a;
	index = a->index_sort;
	while (a)
	{
		if (index >= a->index_sort)
		{
			index = a->index_sort;
			start = a;
		}
		a = a->next;
	}
	a = head;
	count = ft_count(head, start, current_b);
	return (count);
}

int	ft_is_r_rr(t_global g, int a, int b)
{
	int	count_a;
	int	count_b;

	count_a = ft_stacksize(*g.stack_a);
	count_b = ft_stacksize(*g.stack_b);
	if ((ft_optimize(a, count_a) != a
			&& ft_optimize(b, count_b) != b)
		|| (ft_optimize(b, count_b) == b
			&& ft_optimize(a, count_a) == a)
		|| (ft_optimize(a, count_a) != a
			&& ft_ismidel(&b, count_b) > 0)
		|| (ft_optimize(b, count_b) != b
			&& ft_ismidel(&a, count_a) > 0)
		|| (ft_optimize(a, count_a) == a
			&& ft_ismidel(&b, count_b) > 0)
		|| (ft_optimize(b, count_b) == b
			&& ft_ismidel(&a, count_a) > 0))
		return (1);
	return (0);
}

int	ft_conditions(t_global p, int current_b)
{
	int	a;
	int	b;
	int	total;

	a = p.a;
	b = current_b;
	if (ft_is_r_rr(p, a, b))
	{
		if (b != current_b)
			ft_first(&total, p.a, current_b, *p.stack_a);
		else if (a != p.a)
			ft_first(&total, current_b, p.a, *p.stack_b);
		else
			total = ft_second(p, current_b);
	}
	else
		total = ft_theelse(p, current_b);
	return (total);
}

int	ft_getbestmoveindex(t_global push, int current_b)
{
	t_stack	*a;
	t_stack	*b;
	int		perfect;
	int		index;

	a = *push.stack_a;
	b = *push.stack_b;
	perfect = ft_stacksize(a) + ft_stacksize(b);
	index = b->index_sort;
	while (b)
	{
		push.a = ft_movementsfuture(a, b->index_sort);
		push.b = b->index_sort;
		if (perfect > ft_conditions(push, current_b))
		{
			index = b->index_sort;
			perfect = ft_conditions(push, current_b);
		}
		b = b->next;
		current_b++;
		a = *push.stack_a;
	}
	b = *push.stack_b;
	return (index);
}
