/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 10:07:29 by tnakamur          #+#    #+#             */
/*   Updated: 2020/06/30 19:29:39 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*p1;
	const char	*p2;
	size_t		i;

	if (!s1 && !s2)
		return (0);
	p1 = (char *)s1;
	p2 = (const char *)s2;
	i = 0;
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (s1);
}
