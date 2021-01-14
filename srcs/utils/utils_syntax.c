/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:52:57 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/14 19:23:08 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_quote.h"
#include "executor.h"
#include "minishell.h"
#include "utils.h"
#include "libft.h"
#include <unistd.h>
#include "utils_string.h"
#include "utils_syntax.h"
#include "prompt.h"
#include "signal_handle.h"
#include <stdio.h>

int		put_syntax_err(char *msg, char token, int exitcode)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msg, 2);
	write(2, " `", 2);
	ft_putchar_fd(token, 2);
	write(2, "'\n", 2);
	return (exitcode);
}

static int		valid_operator(int c)
{
	if (c == '|' || c == ';')
		return (1);
	return (0);
}

int		parse_syntax(const char *str)
{
	int		cmd;
	char	*tmp;

	cmd = 0;
	tmp = (char *)str;
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	if (valid_operator(*tmp))
		return (*tmp);
	while (*tmp)
	{
		if (is_quote(*tmp))
			tmp = skip_to_next_quote(tmp);
		if (*tmp != ' ' && *tmp != '\t' && !valid_operator(*tmp))
			cmd = 1;
		if (valid_operator(*tmp) && cmd)
			cmd = 0;
		else if (valid_operator(*tmp) && !cmd)
			return (*tmp);
		tmp++;
	}
	return (0);
}

int		check_closed(const char *str, char token)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while ((str[i] == ' ' || str[i] == '\t') && i > 0)
		i--;
	if (str[i] == token)
		return (1);
	return (0);
}


