#include "../includes/minishell.h"

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
	int i;

	(void)args;
	if (env == NULL)
		return (0);
	i = 0;
	while (env[i])
	{
		ft_putendl_fd(env[i], fd);
		i++;
	}
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
