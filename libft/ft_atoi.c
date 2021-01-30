/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:27:21 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/22 14:13:56 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' ||
		c == '\n' || c == '\f')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		if (num > (10 * num + (*str - 48)))
			return ((sign < 0) ? (0) : (-1));
		num = 10 * num + (*str - 48);
		str++;
	}
	return ((int)num * sign);
}
