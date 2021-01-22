/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:42:34 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/22 15:22:34 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env_list_base.h"
#include "my_signal.h"
#include "prompt.h"

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
