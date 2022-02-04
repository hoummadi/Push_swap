/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:00:21 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/02 17:00:23 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

static void	hub_switch(int ac, t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a, stack_b) == 1)
	{
		if (ac <= 3)
			check_three(ac, stack_a, stack_b);
		else if (ac <= 5)
			check_five(ac, stack_a, stack_b);
		else if (ac <= 20)
			check_others(ac, stack_a, stack_b);
		else
			check_hundred(ac, stack_a, stack_b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*st_a;
	t_stack	*st_b;

	ac--;
	if (ac > 0)
	{
		init_stack(&st_a, &st_b, ac);
		check_argv(ac, av + 1, st_a, st_b);
		hub_switch(ac, st_a, st_b);
	}
	return (0);
}
