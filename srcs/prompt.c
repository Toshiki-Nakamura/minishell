#include "../includes/minishell.h"

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

void		input_prompt(char **line, char ***args, char ***env, int *status)
{
	int fd;
	fd = 1;

	ft_putstr_fd("\033[32mshell$> \033[0m", 1);
	*line = get_cmd_line(); // !!! wait return !!!
	// ;	複数コマンドのパース
	// |	パイプ
	// ' "	クォーテーション
	// > >>	リダイレクト fd
	*args = ft_split(*line, ' ');
	*status = sh_execute(*args, *env, fd);

	if (*args != NULL)
		tab_free(*args);
	if (*line != NULL)
		free(*line);
}
