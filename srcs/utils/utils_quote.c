/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:31:45 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/22 14:37:13 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "utils_is.h"

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
