/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:44:31 by skohraku          #+#    #+#             */
/*   Updated: 2021/10/31 13:17:48 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "utils.h"
#include "utils_string.h"
#include "msutils_env_param.h"
#include "msutils_convert.h"
#include "syntax_check.h"
#include "cmd_manager.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#ifdef TEST
# define VAR 1
#else
# define VAR 0
#endif

char	*g_line;

void		input_prompt(void)
{
	g_line = NULL;
	g_line = readline(PROMPT);
	if (g_line == NULL) // Ctrl + D
		g_line = ft_strdup("exit");
	if (ft_strlen(g_line) == 0)
		return ;
	add_history(g_line);
	if (check_syntax(g_line))
	{
		replace_env_param(&g_line);
		remove_comment(&g_line);
		exec_one_line(g_line);
	}
	if (g_line != NULL)
		free(g_line);
}
