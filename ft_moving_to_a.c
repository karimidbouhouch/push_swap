/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 07:55:02 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/02/28 04:18:34 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getthecount(t_stack *b, int index)
{
	t_stack	*tmp;
	int		i;

	tmp = b;
	i = 0;
	while (b)
	{
		if (b->index_sort == index)
			break ;
		i++;
		b = b->next;
	}
	b = tmp;
	return (i);
}

void	ft_rrr_rra_rrb(t_stack **a, t_stack **b, int amoves, int bmoves)
{
	while (amoves && bmoves)
	{
		*a = ft_reverse_rotate(*a);
		*b = ft_reverse_rotate(*b);
		ft_putstr_fd("rrr\n", 1);
		amoves--;
		bmoves--;
	}
	while (amoves)
	{
		*a = ft_reverse_rotate(*a);
		ft_putstr_fd("rra\n", 1);
		amoves--;
	}
	while (bmoves)
	{
		*b = ft_reverse_rotate(*b);
		ft_putstr_fd("rrb\n", 1);
		bmoves--;
	}
	ft_push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	ft_rra_rb(t_stack **a, t_stack **b, int amoves, int bmoves)
{	
	while (amoves)
	{
		*a = ft_reverse_rotate(*a);
		ft_putstr_fd("rra\n", 1);
		amoves--;
	}
	while (bmoves)
	{
		*b = ft_rotate(*b);
		ft_putstr_fd("rb\n", 1);
		bmoves--;
	}
	ft_push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	ft_rr_ra_rb(t_stack **a, t_stack **b, int amoves, int bmoves)
{
	while (amoves && bmoves)
	{
		*a = ft_rotate(*a);
		*b = ft_rotate(*b);
		ft_putstr_fd("rr\n", 1);
		amoves--;
		bmoves--;
	}
	while (amoves)
	{
		*a = ft_rotate(*a);
		ft_putstr_fd("ra\n", 1);
		amoves--;
	}
	while (bmoves)
	{
		*b = ft_rotate(*b);
		ft_putstr_fd("rb\n", 1);
		bmoves--;
	}
	ft_push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	ft_rrb_ra(t_stack **a, t_stack **b, int amoves, int bmoves)
{
	while (amoves)
	{
		*a = ft_rotate(*a);
		ft_putstr_fd("ra\n", 1);
		amoves--;
	}
	while (bmoves)
	{
		*b = ft_reverse_rotate(*b);
		ft_putstr_fd("rrb\n", 1);
		bmoves--;
	}
	ft_push(b, a);
	ft_putstr_fd("pa\n", 1);
}

int	ft_is_rotate(t_stack *b, t_stack *a, int *toa, int *tob)
{
	return ((*tob == ft_optimize(*tob, ft_stacksize(b)) && *toa == ft_optimize(*toa, ft_stacksize(a)))
		|| (*tob == ft_optimize(*tob, ft_stacksize(b)) && ft_ismidel(toa, ft_stacksize(a)) > 0)
		|| (*toa == ft_optimize(*toa, ft_stacksize(a)) && ft_ismidel(tob, ft_stacksize(b)) > 0));
}

int	ft_is_rev_rotate(t_stack *b, t_stack *a, int *toa, int *tob)
{
	return ((*tob != ft_optimize(*tob, ft_stacksize(b)) && *toa != ft_optimize(*toa, ft_stacksize(a)))
		|| (*tob != ft_optimize(*tob, ft_stacksize(b)) && ft_ismidel(toa, ft_stacksize(a)) > 0)
		|| (*toa != ft_optimize(*toa, ft_stacksize(a)) && ft_ismidel(tob, ft_stacksize(b)) > 0));
}

void	ft_move_to_a(t_stack **a, t_stack **b, int index)
{
	t_global	g;
	int	tob;
	int toa;

	tob = ft_getthecount(*b, index);
	toa = ft_movementsfuture(*a, index);
	
	g.tmp_a = toa;
	g.tmp_b = tob;
	// printf("[a = %d |b = %d]\n",toa,tob);
	if (ft_is_rotate(*b, *a, &toa, &tob))
		ft_rr_ra_rb(a, b, toa, tob);
	else if (ft_is_rev_rotate(*b, *a, &toa, &tob))
	{
		if (g.tmp_a != toa || g.tmp_b != tob)
		{
			if (g.tmp_a != toa)
				ft_rrr_rra_rrb(a, b, toa, ft_optimize(tob, ft_stacksize(*b)));
			else
				ft_rrr_rra_rrb(a, b, ft_optimize(toa, ft_stacksize(*a)), tob);
		}
		else
			ft_rrr_rra_rrb(a, b, ft_optimize(g.tmp_a, ft_stacksize(*a)),
			ft_optimize(g.tmp_b, ft_stacksize(*b)));
	}
	else if (tob == ft_optimize(tob, ft_stacksize(*b)) && toa != ft_optimize(toa, ft_stacksize(*a)))
		ft_rra_rb(a, b, ft_optimize(toa, ft_stacksize(*a)), ft_optimize(tob, ft_stacksize(*b)));
	else
		ft_rrb_ra(a, b, ft_optimize(toa, ft_stacksize(*a)), ft_optimize(tob, ft_stacksize(*b)));
}