/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:58:24 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/22 12:10:48 by skohraku         ###   ########.fr       */
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
