/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stdlib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 19:12:28 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/21 22:48:13 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' ||
		c == '\n' || c == '\f')
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long long	num;
	long long	sign;

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
	while (*str && (*str >= '0' && *str <= '9'))
	{
		num = 10 * num + (*str - 48);
		str++;
	}
	return ((long)num * sign);
}
