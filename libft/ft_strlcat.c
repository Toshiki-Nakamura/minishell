/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 19:40:32 by tnakamur          #+#    #+#             */
/*   Updated: 2020/06/30 23:30:51 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t j;
	size_t i;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	while (dst[i])
		i++;
	while (src[k])
		k++;
	if (dstsize <= i)
		k += dstsize;
	else
		k += i;
	while (src[j] && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (k);
}

/*
** int main(int ac, char **av)
** {
**	if (ac == 3)
**	{
**		printf("strlcat %lu\n", strlcat(av[1], av[2], 6));
**		printf("ft_strlcat %lu\n", ft_strlcat(av[1], av[2], 6));
**	}
**	return (0);
** }
*/
