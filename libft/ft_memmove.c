/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 13:59:11 by tnakamur          #+#    #+#             */
/*   Updated: 2020/06/27 23:49:22 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst2;
	unsigned char	*src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	if (src2 < dst2)
	{
		while (len--)
		{
			*(dst2 + len) = *(src2 + len);
		}
	}
	else
	{
		while (len--)
		{
			*dst2++ = *src2++;
		}
	}
	return (dst);
}
