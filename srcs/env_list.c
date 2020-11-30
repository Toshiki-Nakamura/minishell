/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:03:15 by skohraku          #+#    #+#             */
/*   Updated: 2020/11/30 14:26:42 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**init_env_list(char **env)
{
	(void)env;
	return (NULL);
}

void	finalize_env_list()
{

}

int		is_valid_env_list(const char *key)
{
	(void)key;
	return (1);
}

int		set_env_value(const char *key, const char *value)
{
	(void)key;
	(void)value;
	return (0);
}

char	*get_env_value(const char *key)
{
	(void)key;
	return (NULL);
}