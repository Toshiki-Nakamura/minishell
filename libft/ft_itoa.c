/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:41:30 by tnakamur          #+#    #+#             */
/*   Updated: 2020/06/29 22:49:55 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	digit(long n)
{
	long cnt;

	cnt = 1;
	while (n > 9)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char		*ft_itoa(int n)
{
	int			i;
	long		nb;
	char		*str;
	char		*nstr;

	nb = n;
	if (nb < 0)
		nb *= -1;
	if (!(str = (char *)malloc(sizeof(char) * (digit(nb) + 1))))
		return (0);
	i = digit(nb) - 1;
	str[digit(nb)] = '\0';
	while (i >= 0)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	if (n < 0)
	{
		nstr = ft_strjoin("-", str);
		free(str);
		return (nstr);
	}
	return (str);
}

/*
** int main()
** {
** 	int n = -2147483648;
** 	int n = 2147483647;
** 	printf("%s\n", ft_itoa(n));
** 	return 0;
** }
*/
