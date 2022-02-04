/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:37:13 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/03 12:37:15 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->count == 0)
	{
		return (is_stack_sorted(stack_a));
	}
	return (1);
}

int	is_stack_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->count - 1)
	{
		if (stack->st[stack->head + i] > stack->st[stack->head + i + 1])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static void	sort_tab(t_stack *stack, int **tab)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < stack->count - 1)
	{
		j = i + 1;
		while (j < stack->count)
		{
			if ((*tab)[i] > (*tab)[j])
			{
				tmp = (*tab)[i];
				(*tab)[i] = (*tab)[j];
				(*tab)[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	alloc_tab(t_stack *stack, int **tab)
{
	int	i;

	*tab = malloc(sizeof(int) * stack->count);
	if (!(*tab))
		exit_error(NULL, NULL);
	i = 0;
	while (i < stack->count)
	{
		(*tab)[i] = (stack->st[stack->head + i]);
		i++;
	}
	sort_tab(stack, tab);
}

int	pb_print_ret(t_stack *stack_a, t_stack *stack_b, char *str)
{
	push_to(stack_a, stack_b);
	ft_putstr(1, str);
	return (0);
}
