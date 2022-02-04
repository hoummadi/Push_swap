/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:24:02 by hhoummad          #+#    #+#             */
/*   Updated: 2021/09/07 16:24:04 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	resort(int *tab, int ac)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = ac - 1;
	while (i < j)
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i++;
		j--;
	}
}

void	make_empty(t_stack *stack, t_stack *stack_to, char *str)
{
	while (stack->count > 0)
	{
		push_to(stack, stack_to);
		ft_putstr(1, str);
	}
}
