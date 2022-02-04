/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:59:44 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/05 13:59:47 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	small_s(t_stack *stack)
{
	int	i;
	int	small;

	i = 1;
	small = stack->st[stack->head];
	while (i < stack->count)
	{
		if (stack->st[stack->head + i] < small)
			small = stack->st[stack->head + i];
		i++;
	}
	return (small);
}

int	saorra(int *tab, t_stack *stack_a)
{
	int	index;

	stack_a->head += 2;
	index = index_s(tab, stack_a, stack_a->n);
	stack_a->head -= 2;
	if (index <= stack_a->count / 2)
	{
		rotate_stack(stack_a);
		ft_putstr(1, "ra\n");
		return (0);
	}
	else
	{
		sasb_instru(stack_a);
		ft_putstr(1, "sa\n");
		return (0);
	}
	return (1);
}

void	rr_print(t_stack *stack, char *str)
{
	reverse_rotate_stack(stack);
	ft_putstr(1, str);
}

void	r_print(t_stack *stack, char *str)
{
	rotate_stack(stack);
	ft_putstr(1, str);
}
