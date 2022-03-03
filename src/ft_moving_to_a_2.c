/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving_to_a_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 02:21:18 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 03:46:44 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

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
