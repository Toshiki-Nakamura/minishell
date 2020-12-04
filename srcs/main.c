/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:42:34 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/04 22:40:52 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "prompt.h"
#include "env_list.h"

int		main(int ac, char **av, char **env)
{
	int		status;
	char	**args;
	char	*line;

	(void)av;
	if (ac != 1)
		return (0);
	initialize_env_list(env);
	printf("%s\n", get_env_value("TERM_PROGRAM_VERSION"));
	printf("%s\n", get_env_value("?"));
	set_env_value("?=hogehoge");
	printf("%s\n", get_env_value("?"));
	status = 1;
	while (status > 0)
	{
		input_prompt(&line, &args, &env, &status);
	}
	finalize_env_list();
	return (0);
}
