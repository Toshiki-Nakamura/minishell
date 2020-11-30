/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:42:34 by skohraku          #+#    #+#             */
/*   Updated: 2020/11/30 14:03:50 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

int		main(int ac, char **av, char **env)
{
	int		status;
	char	**args;
	char	*line;

	(void)ac;
	(void)av;
	status = 1;
	// init_env_list?
	while (status > 0)
	{
		input_prompt(&line, &args, &env, &status);
	}
	return (0);
}
