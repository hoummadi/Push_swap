/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_cheker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 14:28:18 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/01 14:28:21 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static long	ft_atoi(const char *str)
{
	long	r;
	int		i;
	long	sg;

	sg = 1;
	r = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sg = sg * (-1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (r <= ((9223372036854775807 - (str[i] - 48)) / 10))
			r = r * 10 + (str[i] - 48);
		else
		{
			r = 9223372036854775807;
			break ;
		}
		i++;
	}
	return (r * sg);
}

static int	checkatoi(char *str, t_stack *st_a, t_stack *st_b)
{
	long	i;
	long	j;

	i = 0;
	if (!str)
		exit_error(st_a, st_b);
	if (str[0] == '-' && str[1] != '\0')
		i++;
	j = i;
	while (str[j] == '0')
		j++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			exit_error(st_a, st_b);
		i++;
	}
	if (i - j > 11)
		exit_error(st_a, st_b);
	i = ft_atoi(str);
	if (i > 2147483647 || i < -2147483648)
		exit_error(st_a, st_b);
	return (i);
}

void	check_argv(int ac, char **av, t_stack *st_a, t_stack *st_b)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		st_a->st[i] = checkatoi(av[i], st_a, st_b);
		i++;
	}
	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (st_a->st[i] == st_a->st[j])
				exit_error(st_a, st_b);
			j++;
		}
		i++;
	}
}
