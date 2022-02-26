/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bestmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:13:23 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/02/26 00:48:18 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_countforstart(t_stack *start, int index)
{
	int		answer;
	t_stack	*stmp;
	int		counting;

	counting = 0;
	answer = 0;
	stmp = start;
	while (start)
	{
		counting++;
		if (index > start->index_sort)
		{
			answer = counting;
		}
		else
			break ;
		start = start->next;
	}
	start = stmp;
	return (answer);
}

int	ft_countforhead(t_stack *head, int index, int end)
{
	int		answer;
	t_stack	*stmp;
	int		counting;

	counting = 0;
	stmp = head;
	answer = 0;
	while (head && head->index_sort != end)
	{
		counting++;
		if (index > head->index_sort)
		{
			answer = counting;
		}
		else
			break ;
		head = head->next;
	}
	head = stmp;
	return (answer);
}

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
	int	index;
	int	count;

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

int	ft_optimize(int moves, int count)
{
	if (moves > count / 2)
		return (count - moves);
	return (moves);
}

int	ft_is_r_rr(int moves, t_stack *x)
{
	if (ft_optimize(moves, ft_stacksize(x)) != moves)
		return (0);
	return (1);
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

void	ft_first(int *total, int moves1, int moves2, t_stack *x)
{
	moves1 = ft_optimize(moves1, ft_stacksize(x));
	moves2 = moves2 + 1;
	if (moves1 > moves2)
		*total = moves1;
	else
		*total = moves2;
}

int	ft_second(int a, int b, t_stack *tmpa, t_stack *tmpb)
{
	int	total;

	a = ft_optimize(a, ft_stacksize(tmpa));
	b = ft_optimize(b, ft_stacksize(tmpb));
	if (a > b)
		total = a;
	else
		total = b;
	return (total);
}

int	ft_theelse(t_global corrent, int correntb, t_stack *tmpa, t_stack *tmpb)
{
	int	total;

	corrent.a = ft_optimize(ft_movementsfuture(tmpa, corrent.b),
			ft_stacksize(tmpa));
	correntb = ft_optimize(correntb, ft_stacksize(tmpb));
	total = corrent.a + correntb;
	return (total);
}

int	ft_conditions(t_global p, int current_b)
{
	int	b;
	int	a;
	int	total;

	a = p.a;
	b = current_b;
	if ((ft_is_r_rr(a, *p.stack_a) == 0 && ft_is_r_rr(b, *p.stack_b) == 0)
		|| (ft_is_r_rr(b, *p.stack_b) == 1 && ft_is_r_rr(a, *p.stack_a) == 1)
		|| (ft_is_r_rr(a, *p.stack_a) == 0 && ft_ismidel(&b, ft_stacksize(*p.stack_b)) > 0)
		|| (ft_is_r_rr(b, *p.stack_b) == 0 && ft_ismidel(&a, ft_stacksize(*p.stack_a)) > 0)
		|| (ft_is_r_rr(a, *p.stack_a) == 1 && ft_ismidel(&b, ft_stacksize(*p.stack_b)) > 0)
		|| (ft_is_r_rr(b, *p.stack_b) == 1 && ft_ismidel(&a, ft_stacksize(*p.stack_a)) > 0))
	{
		if (b != current_b)
			ft_first(&total, p.a, current_b, *p.stack_a);
		else if (a != p.a)
			ft_first(&total, current_b, p.a, *p.stack_b);
		else
			total = ft_second(p.a, current_b, *p.stack_a, *p.stack_b);
	}
	else
		total = ft_theelse(p, current_b, *p.stack_a, *p.stack_b);
	return (total);
}

int	ft_bestmovesindex(t_global push, int current_b)
{
	t_stack	*a;
	t_stack	*b;
	int	perfect;
	int index;

	current_b = 0;
	a = *push.stack_a;
	b = *push.stack_b;
	perfect = ft_stacksize(a) + ft_stacksize(b);
	index = b->index_sort;
	while (b)
	{
		push.a = ft_movementsfuture(a, b->index_sort);
		push.b = b->index_sort;
		printf("[a = %d] - [b = %d]\n",push.a,current_b);
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
