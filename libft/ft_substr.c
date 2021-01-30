/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 14:28:52 by tnakamur          #+#    #+#             */
/*   Updated: 2020/06/25 16:18:12 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
** int main(void)
** {
** 	char *str = "test";
** 	char *ans = ft_substr(str, 4, 1);
** 	printf("ft_substr:%s\n", ans);
** 	return 0;
** }
*/
