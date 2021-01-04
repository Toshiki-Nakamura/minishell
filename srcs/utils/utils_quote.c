/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:31:45 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/04 16:22:32 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int			is_quote(int c)
{
	if (c == '\'')
		return (1);
	if (c == '\"')
		return (2);
	return (0);
}

char		*skip_to_next_quote(char *str)
{
	int	target;

	if (!str || ((*str != '"') && (*str != '\'')))
	{
		// perror("head char is not quotation!!!");
		return (NULL);
	}
	target = *str;
	str++;
	while (*str)
	{
		if (*str == target)
			return (str);
		str++;
	}
	// perror("pair of quotation is not found!!!");
	return (str);
}

void		remove_quote(char **line)
{
	char	*tmp;
	char	*new;
	char	*p;
	int		j;

	j = 0;
	tmp = *line;
	new = malloc(sizeof(char) * (ft_strlen(*line) + 1));
	while (*tmp != '\0')
	{
		if (!is_quote(*tmp))
			new[j++] = *tmp;
		if ((is_quote(*tmp)) > 0)
		{
			p = tmp + 1;
			tmp = skip_to_next_quote(tmp);
			while (*p && *p != tmp[0])
				new[j++] = *(p)++;
		}
		tmp++;
	}
	new[j] = '\0';
	free(*line);
	*line = new;
}

void		parse_line(char *line, int *quote)
{
	while (line[0] != '\0')
	{
		if ((*quote = is_quote(line[0])) > 0)
		{
			line = skip_to_next_quote(line);
			if (line[0] == '\0')
			{
				ft_putendl_fd("not closed", 2);
				*quote = (*quote == 2) ? '\"' : '\'';
				break ;
			}
		}
		line++;
	}
}
