/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:04:34 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/03 17:04:36 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

static int	npp(int n, t_stack *stack, int ac, int *tab)
{
	int	i;
	int	start;
	int	end;

	i = stack->head;
	start = stack->middle - n;
	end = stack->middle + n;
	while (i < stack->end)
	{
		if (stack->st[i] >= tab[start] && stack->st[i] < tab[end])
		{
			return (n);
		}
		i++;
	}
	if (n + stack->offset < ac)
		return (n + stack->offset);
	else
		return (ac);
}

int	check_tranch(int *tab, int start, int end, t_stack *stack)
{
	int	i;

	i = stack->head;
	while (i < stack->end)
	{
		if (stack->st[i] >= tab[start] && stack->st[i] < tab[end])
			return (0);
		i++;
	}
	return (stack->offset);
}

int	index_s2(int *tab, t_stack *stack, int n)
{
	int	i;
	int	j;
	int	k;

	i = stack->head;
	j = stack->end + 1;
	while (i <= stack->end)
	{
		k = stack->middle - (n + check_tranch(tab, stack->middle - n,
					stack->middle, stack));
		if (k < 0)
			k = 0;
		while (k < stack->ac && k < stack->middle + (n + check_tranch(tab,
					stack->middle, stack->middle + n, stack)))
		{
			if (tab[k] == stack->st[i])
				return (i);
			k++;
		}
		i++;
		j--;
	}
	return (-1);
}

void	find_index2(int n, t_stack *stack_a, t_stack *stack_b, int *tab)
{
	int	index;

	index = index_s2(tab, stack_a, n);
	if (index != -1)
	{
		if (index - stack_a->head <= stack_a->end + 1 - index)
		{
			stack_a->n = n;
			if (rotate_while(stack_a, stack_b, index) == 1)
				return ;
		}
		else
		{
			if (rev_rotate_while(stack_a, stack_b, index) == 1)
				return ;
		}
		if (stack_b->st[stack_b->head] < tab[stack_b->middle])
		{
			rotate_stack(stack_b);
			ft_putstr(1, "rb\n");
		}
	}
}

void	check_hundred(int ac, t_stack *stack_a, t_stack *stack_b)
{
	int	*tab;
	int	n;
	int	i;

	alloc_tab(stack_a, &tab);
	n = stack_a->offset;
	i = 0;
	while (i < ac)
	{
		find_index2(n, stack_a, stack_b, tab);
		i++;
		if (i >= (n * 2))
		{
			n = npp(n, stack_a, ac, tab);
		}
	}
	make_empty(stack_a, stack_b, "pb\n");
	resort(tab, ac);
	n = 0;
	while (n < ac)
	{
		find_index_b(n, stack_b, stack_a, tab);
		n++;
	}
	free(tab);
}
