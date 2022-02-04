/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:26:14 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/02 13:26:16 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	shift_stack_plus(t_stack *stack)
{
	int	i;

	if (stack->count > 0)
	{
		i = stack->end;
		while (i > stack->head)
		{
			stack->st[i] = stack->st[i - 1];
			i--;
		}
	}
}

void	shift_stack_moin(t_stack *stack)
{
	int	i;

	if (stack->count > 0)
	{
		i = stack->head;
		while (i < stack->end)
		{
			stack->st[i] = stack->st[i + 1];
			i++;
		}
	}
}
