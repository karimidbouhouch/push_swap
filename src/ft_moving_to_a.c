/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 07:55:02 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 03:46:46 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

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

int	ft_is_rotate(t_stack *b, t_stack *a, int *toa, int *tob)
{
	return ((*tob == ft_optimize(*tob, ft_stacksize(b))
			&& *toa == ft_optimize(*toa, ft_stacksize(a)))
		|| (*tob == ft_optimize(*tob, ft_stacksize(b))
			&& ft_ismidel(toa, ft_stacksize(a)) > 0)
		|| (*toa == ft_optimize(*toa, ft_stacksize(a))
			&& ft_ismidel(tob, ft_stacksize(b)) > 0));
}

int	ft_is_rev_rotate(t_stack *b, t_stack *a, int *toa, int *tob)
{
	return ((*tob != ft_optimize(*tob, ft_stacksize(b))
			&& *toa != ft_optimize(*toa, ft_stacksize(a)))
		|| (*tob != ft_optimize(*tob, ft_stacksize(b))
			&& ft_ismidel(toa, ft_stacksize(a)) > 0)
		|| (*toa != ft_optimize(*toa, ft_stacksize(a))
			&& ft_ismidel(tob, ft_stacksize(b)) > 0));
}

void	ft_cond_rev_rotate(t_global g, t_stack **a, t_stack **b)
{
	if (g.tmp_a != g.a || g.tmp_b != g.b)
	{
		if (g.tmp_a != g.a)
			ft_rrr_rra_rrb(a, b, g.a, ft_optimize(g.b, ft_stacksize(*b)));
		else
			ft_rrr_rra_rrb(a, b, ft_optimize(g.a, ft_stacksize(*a)), g.b);
	}
	else
		ft_rrr_rra_rrb(a, b, ft_optimize(g.tmp_a, ft_stacksize(*a)),
			ft_optimize(g.tmp_b, ft_stacksize(*b)));
}

void	ft_move_to_a(t_stack **a, t_stack **b, int index)
{
	t_global	g;
	int			tob;
	int			toa;

	tob = ft_getthecount(*b, index);
	toa = ft_movementsfuture(*a, index);
	g.tmp_a = toa;
	g.tmp_b = tob;
	if (ft_is_rotate(*b, *a, &toa, &tob))
		ft_rr_ra_rb(a, b, toa, tob);
	else if (ft_is_rev_rotate(*b, *a, &toa, &tob))
	{
		g.a = toa;
		g.b = tob;
		ft_cond_rev_rotate(g, a, b);
	}
	else if (tob == ft_optimize(tob, ft_stacksize(*b))
		&& toa != ft_optimize(toa, ft_stacksize(*a)))
		ft_rra_rb(a, b, ft_optimize(toa, ft_stacksize(*a)),
			ft_optimize(tob, ft_stacksize(*b)));
	else
		ft_rrb_ra(a, b, ft_optimize(toa, ft_stacksize(*a)),
			ft_optimize(tob, ft_stacksize(*b)));
}
