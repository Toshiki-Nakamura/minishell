/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:51:19 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/05 14:28:52 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "libft.h"
#include "env_list.h"

static void	get_env_path(char **home, char **env, char *path)
{
	int i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], path, ft_strlen(path)) == 0)
		{
			*home = ft_strdup(env[i] + ft_strlen(path));
			break ;
		}
	}
}

int			exec_cd(char **args, char **env)
{
	char path[MAXPATHLEN];
	char *home;

	if (args[1] == NULL || !ft_strncmp("~/", args[1], 3) || !ft_strncmp("~", args[1], 2))
	{
		getcwd(path, MAXPATHLEN);
		get_env_path(&home, env, "HOME=");
		if (chdir(home) != 0)
			ft_putendl_fd(strerror(errno), 1);
		if (home)
			free(home);
	}
	else
	{
		if (chdir(args[1]) != 0) // error -1, success  0
			ft_putendl_fd(strerror(errno), 1);
	}
	return 1;
}

int			exec_env(char **args, char **env, int fd)
{
	(void)args;
	(void)env;
	(void)fd;
	show_env_list();
	return (1);
}

int			exec_pwd(int fd)
{
	char	path[MAXPATHLEN];

	ft_memset(path, 0, MAXPATHLEN);
	if (!getcwd(path, MAXPATHLEN))
		return (0);
	ft_putendl_fd(path, fd);
	return (1);
}

void		exec_exit(char **args)
{
	(void)args;
	ft_putstr_fd("exit\n", 1);
	exit(0); //引数によって終了ステータスを変更しなければならない
}

static int	is_env(char *str)
{
	if (str[0] == '$')
	{
		if (str[1] != '\0' && str[1] != '$')
			return (1);
		else if (str[1] == '$')
			return (-1);
	}
	return (0);
}

int			exec_echo(char **args, int fd)
{
	int	i;

	i = 1;
	if (args[1] == NULL)
		ft_putstr_fd("", fd);
	if (args[1] && ft_strncmp(args[1], "-n", 3) == 0)
		i++;
	while (args[i])
	{
		if (!is_env(args[i]))
			ft_putstr_fd(args[i], fd);
		else
			ft_putstr_fd((char *)get_env_value(args[i] + 1), fd);
		i++;
		if (args[i] != NULL)
			write(fd, " ", 1);
	}
	if (!args[1] || ft_strncmp(args[1], "-n", 3) != 0)
		write(fd, "\n", 1);
	return (1);
}

int			exec_unset(char **args)
{
	(void)args;
	return (1);
}

static int	search_equal(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int			exec_export(char **args, int fd)
{
	int i;

	(void)args;
	(void)fd;
	i = 0;
	while (args[++i])
	{
		if (!ft_isalpha(args[i][0]) && args[i][0] != '_')
		{
			ft_putstr_fd("export:", 2);
			ft_putstr_fd(args[i], 2);
			ft_putendl_fd(": not a valid identifier", 2);
		}
		else if (search_equal(args[i]) == 1)
			set_env_value(args[i]);
	}
	return (1);
}

void		exec_execve(char **args, char **env, int fd)
{
	(void)fd;
	if ((execve(args[0], args, env)) == -1)
	{
		ft_putstr_fd("shell: ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	exit(EXIT_FAILURE);
}
