/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 13:30:01 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/27 11:10:36 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushlib_bonus.h"

static void	check_if_ok(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_b->count == 0)
	{
		i = 0;
		while (i < stack_a->count - 1)
		{
			if (stack_a->st[i] > stack_a->st[i + 1])
			{
				ft_putstr(1, "KO\n");
				exit(1);
			}
			i++;
		}
		ft_putstr(1, "OK\n");
	}
	else
	{
		ft_putstr(1, "KO\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	char	*line;
	t_stack	*st_a;
	t_stack	*st_b;

	ac--;
	if (ac > 0)
	{
		init_stack(&st_a, &st_b, ac);
		check_argv(ac, av + 1, st_a, st_b);
		while (read_line(&line) != 1)
		{
			execute_instru(st_a, st_b, line);
			free(line);
		}
		check_if_ok(st_a, st_b);
	}
	return (0);
}
