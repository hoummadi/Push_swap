/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_instruction_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 15:02:21 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/27 11:08:30 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_bonus.h"

void	rotate_stack(t_stack *stack)
{
	long	numbre;

	if (stack->count > 0)
	{
		numbre = stack->st[stack->head];
		shift_stack_moin(stack);
		stack->st[stack->end] = numbre;
	}
}

void	rr_stack(t_stack *stack_a, t_stack *stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
}

void	reverse_rotate_stack(t_stack *stack)
{
	long	number;

	if (stack->count > 0)
	{
		number = stack->st[stack->end];
		shift_stack_plus(stack);
		stack->st[stack->head] = number;
	}
}

void	rrr_stack(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
}
