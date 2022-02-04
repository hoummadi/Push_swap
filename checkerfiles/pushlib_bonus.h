/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushlib_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 13:30:15 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/27 11:10:59 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHLIB_BONUS_H
# define PUSHLIB_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "../common_bonus/common_bonus.h"

int		read_line(char **line);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *src);
int		ft_strcmp(char *s1, char *s2);
void	execute_instru(t_stack *st_a, t_stack *st_b, char *line);

#endif
