/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:08:29 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/02 17:08:32 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	long		*st;
	int			head;
	int			end;
	int			count;
	int			offset;
	int			middle;
	int			n;
	int			val1;
	int			val2;
	int			ac;
}				t_stack;

void	init_stack(t_stack **st_a, t_stack **st_b, int ac);
void	check_argv(int ac, char **av, t_stack *st_a, t_stack *st_b);
void	exit_error(t_stack *fr1, t_stack *fr2);
void	ft_putstr(int fd, char *str);
void	sasb_instru(t_stack *stack);
void	ss_instru(t_stack *st_a, t_stack *st_b);
void	push_to(t_stack *from, t_stack *to);
void	shift_stack_plus(t_stack *stack);
void	shift_stack_moin(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	rr_stack(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_stack(t_stack *stack);
void	rrr_stack(t_stack *stack_a, t_stack *stack_b);

#endif
