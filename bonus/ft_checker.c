/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 01:14:35 by kid-bouh          #+#    #+#             */
/*   Updated: 2022/03/03 01:42:29 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_commands_3(const char *line, t_stack **a, t_stack **b)
{
	int	size;

	size = ft_strlen(line);
	if (!ft_strncmp(line, "rrr\n", size))
	{
		*a = ft_reverse_rotate(*a);
		*b = ft_reverse_rotate(*b);
	}
	else
	{
		ft_putstr_fd("error\n", 1);
		return (0);
	}
	return (1);
}

int	ft_commands_2(const char *line, t_stack **a, t_stack **b)
{
	int	size;

	size = ft_strlen(line);
	if (!ft_strncmp(line, "ra\n", size))
		*a = ft_rotate(*a);
	else if (!ft_strncmp(line, "rb\n", size))
		*b = ft_rotate(*b);
	else if (!ft_strncmp(line, "rr\n", size))
	{
		*b = ft_rotate(*b);
		*a = ft_rotate(*a);
	}
	else if (!ft_strncmp(line, "rra\n", size))
		*a = ft_reverse_rotate(*a);
	else if (!ft_strncmp(line, "rrb\n", size))
		*b = ft_reverse_rotate(*b);
	else
		if (!ft_commands_3(line, a, b))
			return (0);
	return (1);
}

int	ft_commands(const char *line, t_stack **a, t_stack **b)
{
	int	size;

	size = ft_strlen(line);
	if (!ft_strncmp(line, "sa\n", size))
		ft_swap(*a);
	else if (!ft_strncmp(line, "sb\n", size))
		ft_swap(*b);
	else if (!ft_strncmp(line, "ss\n", size))
	{
		ft_swap(*a);
		ft_swap(*b);
	}
	else if (!ft_strncmp(line, "pa\n", size))
		ft_push(b, a);
	else if (!ft_strncmp(line, "pb\n", size))
		ft_push(a, b);
	else
		if (!ft_commands_2(line, a, b))
			return (0);
	return (1);
}

int	ft_readline(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!ft_commands(line, a, b))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

void	ft_checker(t_stack *a, t_stack *b)
{
	if (ft_stacksize(b) != 0)
	{
		ft_putstr_fd("KO", 1);
		return ;
	}
	while (a)
	{
		if (a->next && a->value > a->next->value)
		{
			ft_putstr_fd("KO", 1);
			return ;
		}
		a = a->next;
	}
	ft_putstr_fd("OK", 1);
}
