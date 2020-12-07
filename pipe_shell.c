/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:58:58 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/06 15:40:28 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_join(char *s, char c)
{
	char	*new;
	size_t	i;

	if (!(new = malloc(ft_strlen(s) + 2)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	if (s != NULL)
	{
		free(s);
	}
	return (new);
}

static char	*get_cmd_line(void)
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

void	tab_print(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		ft_putendl_fd(tab[i++], 1);
}

void	tab_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

int		tab_size(char **tab)
{
	int i = 0;
	while (tab[i])
		i++;
	return (i);
}
int g_len;

void		executor(int n,char ***cmd, char **env)
{
	int		fd[2];
	pid_t	pid1;

	if (n == g_len - 1)
	{
		if (execve(cmd[0][0], cmd[0], 0) < 0)
			ft_putendl_fd(strerror(errno), 2);
		exit(1);
	}
	else
	{
		pipe(fd);
		pid1 = fork();
		if (pid1 == 0)
		{
			close(fd[0]);
			dup2(fd[1], 1);
			close(fd[1]);

			executor(n + 1, cmd, env);
		}
		else
		{
			close(fd[1]);
			dup2(fd[0], 0);
			close(fd[0]);
			if (execve(cmd[g_len - n - 1][0], cmd[g_len - n - 1], env) == -1)
				ft_putendl_fd(strerror(errno), 2);
			exit(1);
		}
	}
}

int		main(int ac, char **av, char **env)
{
	char	*line;
	char	**args;
	char	***cmdlst;
	pid_t	pid;

	cmdlst = NULL;
	while (1)
	{
		write(1, "minishell $> ", 14);

		line = get_cmd_line();
		args = ft_split(line, '|');
		int len = tab_size(args);
		g_len = len;
		cmdlst = malloc(sizeof(char **) * (len + 1));
		int i = -1;
		while (args[++i])
			cmdlst[i] = ft_split(args[i], ' ');
		cmdlst[i] = NULL;

		if (cmdlst[0])
		{
			pid = fork();
			if (pid == 0)
				executor(0, cmdlst, env);
			else
				wait(NULL);
		}

		if (line != NULL)
			free(line);
		if (args != NULL)
			tab_free(args);
		i = 0;
		while (cmdlst[i] != NULL)
			tab_free(cmdlst[i++]);
		free(cmdlst);
	}
	return (0);
}
