/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ck_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:29:54 by hhoummad          #+#    #+#             */
/*   Updated: 2021/05/28 12:25:28 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushlib_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*p;

	if (!s1 || !s2)
		return (ft_strdup(""));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	p = malloc(sizeof(char) * (i + j + 1));
	if (!p)
		return (NULL);
	k = -1;
	while (++k < i)
		p[k] = s1[k];
	k = 0;
	while (k < j)
	{
		p[i] = s2[k];
		k++;
		i++;
	}
	p[i] = '\0';
	free(s1);
	return (p);
}

char	*ft_strdup(const char *src)
{
	int		s;
	char	*dest;
	int		i;

	if (src == NULL)
		return (ft_strdup(""));
	i = 0;
	s = 0;
	while (src[s] != '\0')
		s++;
	dest = (char *)malloc(sizeof(dest) * (s + 1));
	if (!dest)
		return (NULL);
	while (i <= s)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
