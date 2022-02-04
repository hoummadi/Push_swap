/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 13:54:49 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/27 11:08:09 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_bonus.h"

void	exit_error(t_stack *fr1, t_stack *fr2)
{	
	free(fr1->st);
	free(fr2->st);
	free(fr1);
	free(fr2);
	ft_putstr(2, "Error\n");
	exit(1);
}
