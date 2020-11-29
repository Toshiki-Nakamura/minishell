/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:25:41 by tnakamur          #+#    #+#             */
/*   Updated: 2020/11/29 12:00:45 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include <sys/param.h>
# include <signal.h>
# include "../libft/libft.h"

/* main */
int		sh_execute(char **args, char **env, int fd);
int		sh_launch(char **args, char **env);

/* exec.c */
int		exec_pwd(int fd);
int		exec_cd(char **args, char **env);
void	exec_exit(char **args);
int		exec_env(char **args, char **env, int fd);
//  exec_echo(), exec_export(), exec_unset()...

/* prompt.c */
void	input_prompt(char **line, char ***args, char ***env, int *status);

/* utils.c */
int		ft_strncmp_ex(const char *s1, const char *s2, size_t n);
void	tab_free(char **tab);
int		tab_size(char **tab);

#endif
