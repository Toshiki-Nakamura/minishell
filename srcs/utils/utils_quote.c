/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:31:45 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/24 22:06:20 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

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

static char		*remove_quote(char *line)
{
	char	*new;
	char	*p;
	int		j;

	j = 0;
	new = malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (*line != '\0')
	{
		if (!is_quote(*line))
			new[j++] = *line;
		if ((is_quote(*line)) > 0)
		{
			p = line + 1;
			line = skip_to_next_quote(line);
			while (*p && *p != line[0])
				new[j++] = *(p)++;
		}
		line++;
	}
	new[j] = '\0';
	return (new);
}

void			iter_remove_quote(char **cmd)
{
	char	*new;
	int		i;

	i = 0;
	new = NULL;
	while (cmd[i])
	{
		new = remove_quote(cmd[i]);
		free(cmd[i]);
		cmd[i] = ft_strdup(new);
		if (new)
			free(new);
		i++;
	}
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

#if 0
static int	next_quote(char *new, char *line, int n, int *j)
{
	int i;
	i = n + 1;
	while (line[i] && line[i] != line[n])
		i++;
	if (line[i] == line[n])
	{
		i = n + 1;
		new[(*j)++] = line[i - 1];
		while (line[i] != line[n])
			new[(*j)++] = line[i++];
		new[(*j)++] = line[i];
		return (i);
	}
	i = n;
	while (line[i] != '\0')
		new[(*j)++] = line[i++];
	return (-1);
}

char		*remove_quote(char *line)
{
	char	*new;
	char	quote;
	int		i;
	int		j;
	i = -1;
	j = 0;
	quote = 0;
	new = malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (line[++i] != '\0')
	{
		if (!is_quote(line[i]))
			new[j++] = line[i];
		if ((quote = is_quote(line[i])) > 0)
		{
			quote = line[i];
			i = i + 1;
			while (line[i] != quote && line[i])
				new[j++] = line[i++];
		}
		if (line[i] == '\0')
			break;
	}
	new[j] = '\0';
	return (new);
}

char		*parse_line(char *line, int *quote, int *idx)
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
#endif
