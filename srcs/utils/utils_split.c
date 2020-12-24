/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:56:42 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/24 12:11:22 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils_string.h"
#include "utils_quote.h"
#include "utils.h"

char				g_sep;

static int			is_sep(int c)
{
	if (g_sep == ' ')
	{
		if (c == ' ' || c == '\t')
			return (1);
	}
	else if (c == g_sep)
		return (1);
	return (0);
}

static char			**mem_free(char **tab)
{
	unsigned int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int			cnt_words(const char *str)
{
	int cnt;

	cnt = 0;
	while (str[0])
	{
		if (is_quote(str[0]))
			str = (const char*)skip_to_next_quote((char *)str);
		if (!is_sep(str[0]) && (is_sep(str[1]) || str[1] == '\0'))
			cnt++;
		str++;
	}
	return (cnt);
}

static const char	*skip_to_end(const char *str)
{
	while (*str != '\0')
	{
		if (is_quote(*str))
			str = (const char*)skip_to_next_quote((char *)str);
		if (is_sep(str[1]) || (str[1] == '\0'))
			return (str);
		str++;
	}
	return (str);
}

char				**util_split(const char *str, char c)
{
	char		**new;
	const char	*p;
	int			i;

	if (!str)
		return (NULL);
	g_sep = c;
	if (!(new = malloc(sizeof(char *) * (cnt_words(str) + 1))))
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		if (!is_sep(*str))
		{
			p = str;
			str = skip_to_end(str);
			if (!(new[i++] = ft_substr(p, 0, (size_t)(str - p + 1))))
				return (mem_free(new));
		}
		str++;
	}
	new[i] = NULL;
	return (new);
}

#if 0
/* gcc utils_split.c utils_quote.c utils_string.c ../../libft/libft.a -I../../includes -I../../libft  */
#include <stdio.h>
static void	get_cmd_line(char **line, char c)
{
	char	buf;
	int		ret;

	if (*line == NULL)
		*line = ft_strdup("");
	write(2, "\e[32mminishell$ \e[0m", 21);
	while ((ret = read(0, &buf, 1)))
	{
		if (c != '\n' && buf == '\n')
			ft_putstr_fd("> ", 2);
		if (c != '\n' && c == buf)
		{
			*line = ft_join(*line, buf);
			break ;
		}
		else if (buf == c)
			break;
		*line = ft_join(*line, buf);
	}
}
int		main(int ac, char **av)
{
	char **tab;
	char *line;

	while (1)
	{
		line = NULL;
		get_cmd_line(&line, '\n');
		tab = util_split(line, ' ');
		int i = 0;
		while (tab[i])
		{
			char *new;
			new = remove_quote(tab[i]);
			free(tab[i]);
			tab[i] = new;
			printf("[%s]\n", tab[i]);
			i++;
		}
		mem_free(tab);
		free(line);
	}
	return (0);
}
#endif
