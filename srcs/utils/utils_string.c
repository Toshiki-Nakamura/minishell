/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 21:39:37 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/24 22:24:43 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)str1;
	p2 = (unsigned char *)str2;
	while (*p1 == *p2)
	{
		if ((*p1 == 0) && (*p2 == 0))
		{
			return (0);
		}
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}

char	*ft_join(char *s, char c)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
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

int		ft_cmp_ignore_case(const char *s1, const char *s2, size_t n)
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

char	*ft_strjoin_free(char *s1, char *s2)
{
	char *new;

	new = ft_strjoin(s1, s2);
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	return (new);
}

char	*free_set(char **value, char *next)
{
	if (*value != NULL)
	{
		free(*value);
		*value = next;
	}
	return (*value);
}
