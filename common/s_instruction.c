/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_instruction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 12:41:13 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/02 12:41:15 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sasb_instru(t_stack *stack)
{
	long	tmp;

	if (stack->count >= 2)
	{
		tmp = stack->st[stack->head];
		stack->st[stack->head] = stack->st[stack->head + 1];
		stack->st[stack->head + 1] = tmp;
	}
}

void	ss_instru(t_stack *st_a, t_stack *st_b)
{
	sasb_instru(st_a);
	sasb_instru(st_b);
}

static void	erase(t_stack *stack)
{
	stack->st[stack->head] = 999999999;
	stack->head++;
	stack->count--;
}

void	push_to(t_stack *from, t_stack *to)
{
	long	number;

	if (from->count > 0)
	{
		number = from->st[from->head];
		erase(from);
		if (to->head > 0)
		{
			to->head--;
			to->st[to->head] = number;
			to->count++;
		}
		else
		{
			to->end++;
			to->count++;
			shift_stack_plus(to);
			to->st[to->head] = number;
		}
	}
}
