/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:56:42 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/22 14:09:06 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "utils_is.h"
#include "utils_string.h"
#include "utils_quote.h"

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

static int			cnt_words(const char *str, char *separator)
{
	int cnt;

	cnt = 0;
	while (str[0])
	{
		if (is_quote(str[0]))
			str = (const char*)skip_to_next_quote((char *)str);
		if (!ft_strchr(separator, str[0]) &&
			(ft_strchr(separator, str[1]) || str[1] == '\0'))
			cnt++;
		str++;
	}
	return (cnt);
}

static const char	*skip_to_end(const char *str, char *separator)
{
	while (*str != '\0')
	{
		if (is_quote(*str))
			str = (const char*)skip_to_next_quote((char *)str);
		if (ft_strchr(separator, str[1]) || (str[1] == '\0'))
			return (str);
		str++;
	}
	return (str);
}

char				**util_split(const char *str, char *separator)
{
	char		**new;
	const char	*p;
	int			i;

	if (!str)
		return (NULL);
	if (!(new = malloc(sizeof(char *) * (cnt_words(str, separator) + 1))))
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		if (!ft_strchr(separator, *str))
		{
			p = str;
			str = skip_to_end(str, separator);
			if (!(new[i++] = ft_substr(p, 0, (size_t)(str - p + 1))))
				return (mem_free(new));
		}
		str++;
	}
	new[i] = NULL;
	return (new);
}
