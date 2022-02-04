/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:22:29 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/02 17:22:32 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	fill_stack_b(t_stack *stack, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		stack->st[i] = 999999999;
		i++;
	}
}

static void	check_offset(int ac, t_stack *stack_a, t_stack *stack_b)
{
	if (ac < 150)
	{
		stack_a->offset = ac / 8;
	}
	else
	{
		stack_a->offset = ac / 19;
	}
	stack_b->offset = stack_a->offset;
	stack_a->middle = ac - 1;
	if (ac > 10)
		stack_a->middle = ac / 2;
	stack_b->middle = stack_a->middle;
	stack_a->ac = ac;
	stack_b->ac = ac;
}

void	init_stack(t_stack **st_a, t_stack **st_b, int ac)
{
	*st_a = malloc(sizeof(t_stack));
	if (!(*st_a))
		exit_error(NULL, NULL);
	*st_b = malloc(sizeof(t_stack));
	if (!(*st_b))
		exit_error(NULL, NULL);
	(*st_a)->st = malloc(sizeof(long) * ac);
	(*st_b)->st = malloc(sizeof(long) * ac);
	if (!((*st_a)->st) || !((*st_b)->st))
		exit_error(*st_a, *st_b);
	(*st_a)->count = ac;
	(*st_a)->head = 0;
	(*st_a)->end = ac - 1;
	(*st_b)->count = 0;
	(*st_b)->head = 0;
	(*st_b)->end = -1;
	fill_stack_b(*st_b, ac);
	check_offset(ac, *st_a, *st_b);
}
