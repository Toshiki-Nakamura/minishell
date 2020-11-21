#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "libft//libft.h"

int		sh_launch(char **args, char **env)
{
	pid_t pid;
	pid_t wpid;
	int status;

	pid = fork();
	/* printf("ppid = [%d]\n", pid); */
	if (pid == 0) // 子プロセス
	{
		if (execve(args[0], args, env) == -1)
			printf("shell: %s: %s\n",strerror(errno), args[0]);
		// execve() に成功すると、プロセスID 等は変わらずに
		// 実行プログラムに処理が置き換わるため 以下は実行されない
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("minish"); //fork でエラー
	else //親プロセス
	{
		wait(&status);//子プロセスが実行し終わるまで待つ
		// do {
		// 	wpid = waitpid(pid, &status, WUNTRACED);
		// } while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

void	get_env_path(char **home, char **env, char *path)
{
	int i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(path, env[i], ft_strlen(path)) == 0)
		{
			*home = ft_strdup(env[i] + ft_strlen(path));
			break ;
		}
	}
}

int 	exec_cd(char **args, char **env) 
{
	char path[MAXPATHLEN];
	char *home;

	if (args[1] == NULL || !ft_strncmp("~/", args[1], 3) || !ft_strncmp("~", args[1], 2))
	{
		//home = getenv("HOME"); // "Users/home"
		getcwd(path, MAXPATHLEN);
		get_env_path(&home, env, "HOME=");
		if (chdir(home) != 0)
			ft_putendl_fd(strerror(errno), 1);
	}
	else
	{
		if (chdir(args[1]) != 0) // error -1, success  0
			ft_putendl_fd(strerror(errno), 1);
	}
	return 1;
}

int		exec_env(char **args, char **env)
{
	int i;

	i = -1;
	while (env[++i])
	{
		ft_putendl_fd(env[i], 1);
	}
	return (1);
}

int		sh_execute(char **args, char **env)
{
	int i;

	if (args[0] == NULL) {
		return 1;
	}
	if (ft_strncmp(args[0], "cd", 3) == 0)
	{
		return (exec_cd(args, env));
	}
	if (ft_strncmp(args[0], "pwd", 4) == 0)
	{
		char path[MAXPATHLEN] = {0};
		getcwd(path, MAXPATHLEN);
		printf("%s\n", path);
		return (1);
	}
	if (ft_strncmp(args[0], "env", 4) == 0)
	{
		return (exec_env(args, env));
	}
	if (ft_strncmp(args[0], "exit", 5) == 0)
	{
		ft_putstr_fd("exit\n", 1);
		exit(EXIT_SUCCESS);
		return (1);
	}
	return (sh_launch(args, env));
}

char	*ft_join(char *s, char c)
{
	char	*new;
	int		i;

	if (!(new = malloc(ft_strlen(s) + 2)))
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s))
	{
		new[i] = s[i];
	}
	new[i] = c;
	new[i + 1] = '\0';
	if (s != NULL)
	{
		free(s);
	}
	return (new);
}

char	*get_cmdline(void)
{
	char	*line;
	char	buf;
	int		ret;

	line = ft_strdup("");
	while ((ret = read(0, &buf, 1)))
	{
		if (buf == '\n')
			break ;
		line = ft_join(line, buf);
	}
	if (ret == -1)
		exit(0);
	return (line);
}

void	tab_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	init_prompt(char **line, char ***args, char ***env, int *status)
{
	// ft_putstr_fd("\033[31m", 1);
	ft_putstr_fd("\033[31mshell$> \033[0m", 1);
	// ft_putstr_fd("\033[0m", 1);

	*line = get_cmdline();
	*args = ft_split(*line, ' ');
	*status = sh_execute(*args, *env);

	if (*args != NULL)
		tab_free(*args);
	if (*line != NULL)
		free(*line);
}

void	start_shell(void)
{
	int		status;
	char	**args;
	char	**env;
	char	*line;

	init_prompt(&line, &args, &env, &status);
	while (status > 0)
	{
		init_prompt(&line, &args, &env, &status);
		// init_prompt(*line, **args, **env, &status);
	}
}

int		main(int ac, char **av, char **env)
{
	int		status;
	char	**args;
	char	*line;

	init_prompt(&line, &args, &env, &status);

	while (status > 0)
	{
		init_prompt(&line, &args, &env, &status);
	}
	// start_shell();
	return (0);
}
