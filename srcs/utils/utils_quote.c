/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:31:45 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/15 14:52:13 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			is_quote(int c)
{
	if (c == '\'')
		return (1);
	if (c == '\"')
		return (2);
	return (0);
}

static int	next_quote(char *new, char *line, int n, int *j)
{
	int i;

	i = n + 1;
	while (line[i] && line[i] != line[n])
		i++;
	if (line[i] == line[n])
	{
		i = n + 1;
		while (line[i] != line[n])
			new[(*j)++] = line[i++];
		return (i);
	}
	i = n;
	while (line[i] != '\0')
		new[(*j)++] = line[i++];
	return (-1);
}

char		*clean_line(char *line, int *quote, int *idx)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (line[++i] != '\0')
	{
		if (!is_quote(line[i]))
			new[j++] = line[i];
		if ((*quote = is_quote(line[i])) > 0)
		{
			*idx = j;
			if ((i = next_quote(new, line, i, &j)) < 0)
			{
				*quote = (*quote == 2) ? '\"' : '\'';
				break ;
			}
		}
	}
	new[j] = '\0';
	return (new);
}