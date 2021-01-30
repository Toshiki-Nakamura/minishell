/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:05:49 by tnakamur          #+#    #+#             */
/*   Updated: 2020/06/26 22:31:06 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strchr2(const char *set, char c)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	size_t	len;

	i = 0;
	end = 0;
	if (!s1 && !set)
		return (0);
	else if (!s1)
		return (0);
	else if (!set)
		return (ft_strdup(s1));
	while (s1[end])
		end++;
	end--;
	while (s1[end] && ft_strchr2(set, s1[end]))
		end--;
	while (s1[i] && ft_strchr2(set, s1[i]))
		i++;
	len = (end - i) + 1;
	if (end < i)
		len = 1;
	return (ft_substr(s1, (unsigned int)i, len));
}

/*
** int main(void)
** {
** 	char *s1 = "\t\n \t\t \n\n \n \t\n";
** 	char *set = " \n\t";
** 	printf("%s", ft_strtrim(s1, set));
** 	return 0;
** }
*/
