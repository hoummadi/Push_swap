/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:03:28 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/03 17:03:32 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	check_others(int ac, t_stack *stack_a, t_stack *stack_b)
{
	int	*tab;
	int	n;

	alloc_tab(stack_a, &tab);
	n = 0;
	while (n < ac)
	{
		find_index(n, stack_a, stack_b, tab);
		n++;
	}
	while (stack_b->count > 0)
	{
		push_to(stack_b, stack_a);
		printf("pa\n");
	}
	free(tab);
}
