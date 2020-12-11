/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:39:08 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/11 16:58:09 by tnakamur         ###   ########.fr       */
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
extern char		**g_env;

void			show_env_list(void);
void			show_export_list(void);
//void			show_env_list_contents(t_list *p, int is_reverse);
t_env_info		*create_env_info(const char *env);
void			delete_env_info(void *info);
int				cmp_env_key(void *info, const char *key);

#endif
