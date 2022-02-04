/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:50:57 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/04 11:51:03 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

static void	rotate_while_b(t_stack *stack_b, t_stack *stack_a, int idx)
{
	while (idx - stack_b->head > 0)
	{
		if (stack_b->st[stack_b->head] == stack_b->val1)
		{
			push_to(stack_b, stack_a);
			ft_putstr(1, "pa\n");
			continue ;
		}
		if (stack_b->st[stack_b->head] == stack_b->val2)
		{
			push_to(stack_b, stack_a);
			ft_putstr(1, "pa\n");
			rotate_stack(stack_a);
			ft_putstr(1, "ra\n");
			continue ;
		}
		rotate_stack(stack_b);
		ft_putstr(1, "rb\n");
		idx--;
	}
	if (stack_b->count > 0)
	{
		push_to(stack_b, stack_a);
		ft_putstr(1, "pa\n");
	}
}

static void	r_rotate_while_b(t_stack *stack_a, t_stack *stack_b, int idx)
{
	while (stack_a->end + 1 - idx > 0)
	{
		if (stack_a->st[stack_a->head] == stack_a->val1)
		{
			push_to(stack_a, stack_b);
			ft_putstr(1, "pa\n");
		}
		if (stack_a->st[stack_a->head] == stack_a->val2)
		{
			push_to(stack_a, stack_b);
			ft_putstr(1, "pa\n");
			rotate_stack(stack_b);
			ft_putstr(1, "ra\n");
			continue ;
		}
		reverse_rotate_stack(stack_a);
		ft_putstr(1, "rrb\n");
		idx++;
	}
	if (stack_a->count > 0)
	{
		push_to(stack_a, stack_b);
		ft_putstr(1, "pa\n");
	}
}

static void	check_more(int n, t_stack *stack_b)
{
	if (stack_b->count > 1 && \
		stack_b->st[stack_b->head] > stack_b->st[stack_b->head + 1])
	{
		ft_putstr(1, "sa\n");
		sasb_instru(stack_b);
	}
	if (stack_b->count > 3 && \
		stack_b->st[stack_b->head + 1] > stack_b->st[stack_b->head + 2])
	{
		ft_putstr(1, "ra\n");
		rotate_stack(stack_b);
		ft_putstr(1, "sa\n");
		sasb_instru(stack_b);
		ft_putstr(1, "rra\n");
		reverse_rotate_stack(stack_b);
	}
	if (stack_b->count - n > 1 && \
		stack_b->st[stack_b->head] > stack_b->st[stack_b->end])
	{
		ft_putstr(1, "rra\n");
		reverse_rotate_stack(stack_b);
	}
}

void	find_index_b(int n, t_stack *stack_a, t_stack *stack_b, int *tab)
{
	int	idx;

	idx = index_s(tab, stack_a, n);
	if (idx != -1)
	{
		if (stack_b->count + 2 < stack_b->ac)
		{
			stack_a->val1 = tab[stack_b->count + 1];
			stack_a->val2 = tab[stack_b->count + 2];
		}
		if (idx - stack_a->head <= stack_a->end + 1 - idx)
			rotate_while_b(stack_a, stack_b, idx);
		else
			r_rotate_while_b(stack_a, stack_b, idx);
	}
	check_more(n, stack_b);
}
