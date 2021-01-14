/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:42:34 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/14 14:46:30 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal_handle.h>
#include "env_list.h"
#include "prompt.h"
#include "env_list_base.h"
#include "signal.h"

int		main(int ac, char **av, char **env)
{
	(void)av;
	if (ac != 1)
		return (0);
	initialize_env_list(env);
	while (1)
	{
		signal(SIGINT, in_prompt);
		signal(SIGQUIT, in_prompt);
		input_prompt();
	}
	return (0);
}
