/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:11:52 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/02 02:24:13 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*p;

	if (!*lst)
		ft_stackadd_front(lst, new);
	else
	{
		p = ft_stacklast((*lst));
		p->next = new;
	}
}

t_stack	*ft_stacknew(int value, int index)
{
	t_stack	*p;

	p = malloc(sizeof(t_stack));
	if (!p)
		return (NULL);
	p->value = value;
	p->index_sort = index;
	p->pushtob = 0;
	p->count = 0;
	p->next = NULL;
	return (p);
}

t_stack	*ft_fill_stack(char **numbers)
{
	t_stack	*s;
	t_stack	*head;
	int		i;

	i = -1;
	head = NULL;
	while (numbers[++i])
	{
		s = ft_stacknew(ft_atoi(numbers[i]), 0);
		ft_stackadd_back(&head, s);
	}
	return (head);
}

t_stack	*ft_stack_before_last(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	while (stack->next)
	{
		tmp = stack;
		stack = stack->next;
	}
	return (tmp);
}
