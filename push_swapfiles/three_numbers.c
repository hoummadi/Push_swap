/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:36:46 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/03 12:36:48 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

static void	last_three(t_stack *stack)
{
	if (is_stack_sorted(stack) == 1)
	{
		ft_putstr(1, "sa\n");
		sasb_instru(stack);
	}
}

static void	first_three(t_stack *stack)
{
	ft_putstr(1, "ra\n");
	rotate_stack(stack);
	last_three(stack);
}

static void	middle_three(t_stack *stack)
{
	ft_putstr(1, "rra\n");
	reverse_rotate_stack(stack);
	last_three(stack);
}

static void	check_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->count > 0
		&& stack_a->st[stack_a->head] > stack_a->st[stack_a->head + 1])
	{
		if (stack_b->count > 0
			&& stack_b->st[stack_b->head] < stack_b->st[stack_b->head + 1])
		{
			ft_putstr(1, "ss\n");
			sasb_instru(stack_b);
		}
		else
			ft_putstr(1, "sa\n");
		sasb_instru(stack_a);
	}
	else if (stack_b->count > 0
		&& stack_b->st[stack_b->head] < stack_b->st[stack_b->head + 1])
	{
		ft_putstr(1, "sb\n");
		sasb_instru(stack_b);
	}
}

void	check_three(int ac, t_stack *stack, t_stack *stack_b)
{
	int	i;

	if (ac == 2)
	{
		check_ss(stack, stack_b);
	}
	else if (ac == 3 && is_stack_sorted(stack) == 1)
	{
		i = stack->head;
		if (stack->st[i] > stack->st[i + 1] && stack->st[i] > stack->st[i + 2])
			first_three(stack);
		else if (stack->st[i + 1] > stack->st[i]
			&& stack->st[i + 1] > stack->st[i + 2])
			middle_three(stack);
		else if (stack->st[i + 2] > stack->st[i + 1]
			&& stack->st[i + 2] > stack->st[i])
			last_three(stack);
	}
}
