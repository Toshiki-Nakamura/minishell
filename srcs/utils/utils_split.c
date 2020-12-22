/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:56:42 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/22 20:39:05 by tnakamur         ###   ########.fr       */
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

/*
** int		main(int ac, char **av)
** {
** 	char **tab;
** 	int i = 0;
** 	tab = util_split("", ' ');
** 	while (tab[i])
** 	{
** 		ft_putchar_fd('[',1);
** 		ft_putstr_fd(tab[i++], 1);
** 		ft_putstr_fd("]\n",1);
** 	}
** 	return (0);
** }
*/
