/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_exec_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:05:55 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/27 11:10:46 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushlib_bonus.h"

void	execute_instru(t_stack *st_a, t_stack *st_b, char *line)
{
	if (!ft_strcmp(line, "sa"))
		sasb_instru(st_a);
	else if (!ft_strcmp(line, "sb"))
		sasb_instru(st_b);
	else if (!ft_strcmp(line, "ss"))
		ss_instru(st_a, st_b);
	else if (!ft_strcmp(line, "pa"))
		push_to(st_b, st_a);
	else if (!ft_strcmp(line, "pb"))
		push_to(st_a, st_b);
	else if (!ft_strcmp(line, "ra"))
		rotate_stack(st_a);
	else if (!ft_strcmp(line, "rb"))
		rotate_stack(st_b);
	else if (!ft_strcmp(line, "rr"))
		rr_stack(st_a, st_b);
	else if (!ft_strcmp(line, "rra"))
		reverse_rotate_stack(st_a);
	else if (!ft_strcmp(line, "rrb"))
		reverse_rotate_stack(st_b);
	else if (!ft_strcmp(line, "rrr"))
		rrr_stack(st_a, st_b);
	else
		exit_error(st_a, st_b);
}
