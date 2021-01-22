/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msutils_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:52:57 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/22 15:18:13 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "minishell.h"
#include "libft.h"
#include "utils.h"
#include "utils_is.h"
#include "utils_string.h"
#include "utils_quote.h"
#include "msutils_syntax.h"
#include "msutils_env_param.h"
#include "prompt.h"
#include "my_signal.h"

int		put_syntax_err(char *msg, char token, int exitcode)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msg, 2);
	write(2, " `", 2);
	ft_putchar_fd(token, 2);
	write(2, "'\n", 2);
	return (exitcode);
}

static void		redirect_error(char *str)
{
	if (*str == '\0')
		set_exit_code(error_handle(NULL, NULL, SYNTAX_ERROR" `newline'", 258));
	else if (!ft_strncmp(str, ">>", 2))
		set_exit_code(error_handle(NULL, NULL, SYNTAX_ERROR" `>>'", 258));
	else if (!ft_strncmp(str, "<<", 2))
		set_exit_code(error_handle(NULL, NULL, SYNTAX_ERROR" `<<'", 258));
	else if (!ft_strncmp(str, "<>", 2))
		set_exit_code(error_handle(NULL, NULL, SYNTAX_ERROR" `<>'", 258));
	else
		set_exit_code(put_syntax_err(SYNTAX_ERROR, *str, 258));
}

static char		*redirect_parse(const char *p)
{
	char *str;

	str = (char *)p;
	if (is_redirect_operator(str[0]) == 0)
		return (str);
	if (!ft_strncmp(str, ">>", 2))
		str++;
	str++;
	while (*str != '\0' && ft_strchr(COMMAND_SEPARAT_SPACES, *str))
	{
		str++;
	}
	if (is_redirect_operator(*str) || *str == '\0' || is_control_operator(*str))
	{
		redirect_error(str);
		return (NULL);
	}
	// return ((is_quote(*str)) ? str - 1 : str);
	return (str);
}

int		parse_syntax(const char *str)
{
	int		cmd;
	char	*p;

	cmd = 0;
	p = (char *)str;
	while (ft_strchr(COMMAND_SEPARAT_SPACES, *p))
		p++;
	if (is_control_operator(*p))
		return (*p);
	while (*p)
	{
		if (!(p = redirect_parse(p)))
			return (1);
		if (is_quote(*p))
			p = skip_to_next_quote(p);
		if (!ft_strchr(COMMAND_SEPARAT_SPACES, *p) && !is_control_operator(*p))
			cmd = 1;
		if (is_control_operator(*p) && cmd)
			cmd = 0;
		else if (is_control_operator(*p) && !cmd)
			return (*p);
		p++;
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
	while (ft_strchr(COMMAND_SEPARAT_SPACES, str[i]) && i > 0)
		i--;
	if (str[i] == token)
		return (1);
	return (0);
}


