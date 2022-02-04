/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:36:58 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/03 12:37:01 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	index_s(int *tab, t_stack *stack, int n)
{
	int	i;
	int	j;
	int	k;

	i = stack->head;
	j = stack->end + 1;
	while (i <= j)
	{
		k = 0;
		while (k <= n)
		{
			if (tab[k] == stack->st[i])
				return (i);
			if (tab[k] == stack->st[j] && j < stack->end + 1)
				return (j);
			k++;
		}
		i++;
		j--;
	}
	return (-1);
}

int	rotate_while(t_stack *stack_a, t_stack *stack_b, int index)
{
	while (index - stack_a->head > 0 && is_stack_sorted(stack_a) == 1)
	{
		r_print(stack_a, "ra\n");
		index--;
	}
	if (is_stack_sorted(stack_a) == 1)
		return (pb_print_ret(stack_a, stack_b, "pb\n"));
	return (1);
}

int	rev_rotate_while(t_stack *stack_a, t_stack *stack_b, int index)
{
	while (stack_a->end + 1 - index > 0 && is_stack_sorted(stack_a) == 1)
	{
		rr_print(stack_a, "rra\n");
		index++;
	}
	if (is_stack_sorted(stack_a) == 1)
		return (pb_print_ret(stack_a, stack_b, "pb\n"));
	return (1);
}

int	find_index(int n, t_stack *stack_a, t_stack *stack_b, int *tab)
{
	int	index;

	index = index_s(tab, stack_a, n);
	if (index != -1)
	{
		if (index - stack_a->head <= stack_a->end + 1 - index)
		{
			stack_a->n = n;
			if (rotate_while(stack_a, stack_b, index) == 1)
				return (1);
		}
		else
		{
			if (rev_rotate_while(stack_a, stack_b, index) == 1)
				return (1);
		}
	}
	return (0);
}

void	check_five(int ac, t_stack *stack_a, t_stack *stack_b)
{
	int	*tab;

	alloc_tab(stack_a, &tab);
	while (stack_a->count > 3)
	{
		if (find_index(ac - 4, stack_a, stack_b, tab) == 1)
			break ;
	}
	check_three(stack_a->count, stack_a, stack_b);
	while (stack_b->count > 0)
	{
		push_to(stack_b, stack_a);
		ft_putstr(1, "pa\n");
	}
	check_three(2, stack_a, stack_b);
	free(tab);
}
