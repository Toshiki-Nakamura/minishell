/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:58:24 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/04 21:41:24 by skohraku         ###   ########.fr       */
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
