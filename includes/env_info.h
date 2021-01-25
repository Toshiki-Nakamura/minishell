/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:39:08 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/25 13:40:27 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_INFO_H
# define ENV_INFO_H

# define ENV_KEY_QUESTION	"?"

# include "libft.h"

typedef struct	s_env_info
{
	char	*key;
	char	*value;
}				t_env_info;

extern t_list	*g_env_list_top;
extern char		*g_env_question;

t_env_info		*create_env_info(const char *env);
void			*copy_env_info(t_list *lst);
void			delete_env_info(void *info);
int				cmp_env_key(void *info, const char *key);

#endif
