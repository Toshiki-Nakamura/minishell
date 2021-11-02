/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:44:31 by skohraku          #+#    #+#             */
/*   Updated: 2021/11/01 21:26:45 by tnakamur         ###   ########.fr       */
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

void	input_prompt(void)
{
	char	*cmd_line;

	cmd_line = readline(PROMPT);
	if (cmd_line == NULL)
		cmd_line = ft_strdup("exit");
	if (ft_strlen(cmd_line) == 0)
		return ;
	add_history(cmd_line);
	if (check_syntax(cmd_line))
	{
		replace_env_param(&cmd_line);
		remove_comment(&cmd_line);
		exec_one_line(cmd_line);
	}
	if (cmd_line != NULL)
		free(cmd_line);
}
