/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:58:24 by skohraku          #+#    #+#             */
/*   Updated: 2020/11/30 14:05:38 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	tab_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int		tab_size(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		ft_strncmp_ex(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			if ((unsigned char)s1[i] - (unsigned char)s2[i] != -32)
			{
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			}
		}
		i++;
	}
	return (0);
}

char	*ft_join(char *s, char c)
{
	char	*new;
	size_t	i;

	if (!(new = malloc(ft_strlen(s) + 2)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	if (s != NULL)
	{
		free(s);
	}
	return (new);
}