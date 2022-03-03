/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:11:52 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/03 01:24:44 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		if (!s || ft_atoi(numbers[i]) > 2147483647
			|| ft_atoi(numbers[i]) < -2147483648)
		{
			ft_free(&s);
			ft_putstr_fd("error", 1);
			exit(1);
		}
		ft_stackadd_back(&head, s);
	}
	return (head);
}
