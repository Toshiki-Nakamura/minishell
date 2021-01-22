/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:06:51 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/22 14:18:50 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_quote(int c)
{
	if (c == '\'')
		return (1);
	if (c == '\"')
		return (2);
	return (0);
}

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' ||
		c == '\n' || c == '\f')
		return (1);
	return (0);
}

int		is_printable(char c, char *except)
{
	if ((' ' <= c) && (c <= '~'))
	{
		while (*except != 0)
		{
			if (*except++ == c)
				return (0);
		}
		return (1);
	}
	return (0);
}

int		is_control_operator(int c)
{
	if (c == '|' || c == ';')
		return (1);
	return (0);
}

int		is_redirect_operator(int c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}