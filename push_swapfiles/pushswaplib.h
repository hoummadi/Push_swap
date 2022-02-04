/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswaplib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:01:29 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/02 17:01:31 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAPLIB_H
# define PUSHSWAPLIB_H

# include <stdlib.h>
# include <unistd.h>
# include "../common/common.h"

void	check_three(int ac, t_stack *stack_a, t_stack *stack_b);
int		is_stack_sorted(t_stack *stack);
int		is_sorted(t_stack *stack_a, t_stack *stack_b);
void	alloc_tab(t_stack *stack, int **tab);
void	check_five(int ac, t_stack *stack_a, t_stack *stack_b);
int		find_index(int n, t_stack *stack_a, t_stack *stack_b, int *tab);
void	check_others(int ac, t_stack *stack_a, t_stack *stack_b);
void	check_hundred(int ac, t_stack *stack_a, t_stack *stack_b);
int		index_s(int *tab, t_stack *stack, int n);
void	find_index_b(int n, t_stack *stack_a, t_stack *stack_b, int *tab);
int		small_s(t_stack *stack);
int		rotate_while(t_stack *stack_a, t_stack *stack_b, int index);
int		rev_rotate_while(t_stack *stack_a, t_stack *stack_b, int index);
void	rr_print(t_stack *stack, char *str);
void	r_print(t_stack *stack, char *str);
int		pb_print_ret(t_stack *stack_a, t_stack *stack_b, char *str);
int		saorra(int *tab, t_stack *stack_a);
void	resort(int *tab, int ac);
void	make_empty(t_stack *stack, t_stack *stack_to, char *str);

#endif
