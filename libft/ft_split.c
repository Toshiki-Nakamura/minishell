/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:50:29 by tnakamur          #+#    #+#             */
/*   Updated: 2020/09/11 20:17:27 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**mem_free(char **tab)
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

static int	cnt_words(char const *s, char c)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || (s[i] != c && s[i - 1] == c))
			cnt++;
		i++;
	}
	return (cnt);
}

char		**ft_split(char const *s, char c)
{
	char	**str;
	int		bgn;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (cnt_words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || (s[i] != c && s[i - 1] == c))
			bgn = i;
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
		{
			if (!(str[j++] = ft_substr(s, bgn, (size_t)(i - bgn + 1))))
				return (mem_free(str));
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

/*
** #include <stdio.h>
** int	main(void)
** {
** 	int     index;
** 	char  **tab;
** 	// tab = ft_split("      split       this for   me  !", ' ');
** 	// tab = ft_split("AxBxCCCxDDxxxXxxxxDDxEExxxFxxxxxx", 'x');
** 	tab = ft_split("\0aaaaaaaaa", '\0');
** 	int i = 0;
** 	while (tab[i])
** 	{
** 		printf("%s|\n", tab[i++]);
** 	}
** }
*/
