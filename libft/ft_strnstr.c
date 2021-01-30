/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:46:12 by tnakamur          #+#    #+#             */
/*   Updated: 2020/06/29 23:21:35 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	if (!*needle)
		return ((char*)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (i + j < len && haystack[i + j] &&
					haystack[i + j] == needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}

/*
** int main(int ac, char **av)
**  {
** 	if (ac == 3)
** 	{
** 		printf("ft_strnstr:%s\n", ft_strnstr(av[1], av[2], 4));
** 		printf("   strnstr:%s\n", strnstr(av[1], av[2], 4));
** 	}
** 	return (0);
** }
*/
