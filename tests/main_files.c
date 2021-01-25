#include <stdio.h>
#include "libft.h"
#include "files.h"
#include "env_config.h"

void	test_replace_tilde(char *str)
{
	char	*p = ft_strdup(str);
	replace_tilde(&p);
	printf("[%s] replaced to [%s]\n", str, p);
	free(p);
}

int		main(int ac, char **av, char **env)
{
	(void)av;
	if (ac != 1)
		return (0);
	initialize_env_list(env);
	test_replace_tilde("~");
	test_replace_tilde("~shogo");
	test_replace_tilde("~/");
	test_replace_tilde("~/a.txt");
	test_replace_tilde("~work");

	system("leaks minishell");
	return (0);
}