/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:58:24 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/26 20:45:51 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	array_free(char **array)
{
	int i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

int		array_size(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	ft_swap(void **l1, void **l2)
{
	void *tmp;

	tmp = *l1;
	*l1 = *l2;
	*l2 = tmp;
}

int		error_handle(char *cmd, char *arg, char *msg, int exitcode)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	if (cmd != NULL)
		ft_putstr_fd(": ", 2);
	ft_putstr_fd(arg, 2);
	if (arg != NULL)
		ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
	return (exitcode);
}

int		is_include(char *name, char c)
{
	int i;

	i = 0;
	while (name[i])
	{
		if (name[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
