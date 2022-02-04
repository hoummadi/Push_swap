/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instru_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 15:00:57 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/27 11:10:42 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushlib_bonus.h"

int	read_line(char **line)
{
	char	*buf;
	int		i;

	*line = NULL;
	i = 1;
	buf = malloc(sizeof(char) * 2);
	*line = malloc(sizeof(char));
	if (!(*line) || !buf)
		exit_error(NULL, NULL);
	*line[0] = '\0';
	while (read(0, buf, 1))
	{
		buf[1] = '\0';
		i = 0;
		if (buf[0] == '\n')
			buf[0] = '\0';
		*line = ft_strjoin(line[0], buf);
		if (!(*line))
			exit_error(NULL, NULL);
		if (buf[0] == '\0')
			break ;
	}
	free(buf);
	return (i);
}
