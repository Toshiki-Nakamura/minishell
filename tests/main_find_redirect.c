#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "env_list_base.h"
#include "utils_redirect.h"
#include "utils_env_param.h"
#include "utils_string_operation.h"

void	test_get_redirect_length(char *cmd)
{
	int ret = get_redirect_length(cmd);
	printf("length(%d) in [%s]\n", ret, cmd);
}

void	test_get_envparam_length(char *cmd)
{
	int ret = get_envparam_length(cmd);
	printf("length(%d) in [%s]\n", ret, cmd);
}

void	test_separate_redirect_word(char *cmd)
{
	char *word;
	char *str = ft_strdup(cmd);
	word = NULL;
	if (separate_redirect_word(&str, &word))
	{
		printf("[%s] separated [%s] and [%s]\n", cmd, str, word);
		if (word)
			free(word);
		test_separate_redirect_word(str);
	}
	if (str)
		free(str);
}

void	test_replace_env_param(char *cmd)
{
	char *str = ft_strdup(cmd);
	replace_env_param(&str);
	printf("[%s] replaced [%s]\n", cmd, str);
	if (str)
		free(str);
}

int		main(int ac, char **av, char **env)
{
	(void)av;
	if (ac != 1)
		return (0);

	printf("--- test_get_redirect_length ---\n");
	test_get_redirect_length(">hoge");
	test_get_redirect_length("> hoge");
	test_get_redirect_length(">   hoge");
	test_get_redirect_length(">> hoge   ");
	test_get_redirect_length(">< hoge");
	test_get_redirect_length(">>>hoge  ");
	test_get_redirect_length(">>> hoge");
	test_get_redirect_length("<fuga   ");
	test_get_redirect_length("<   fuga   ");
	test_get_redirect_length("<>fuga   ");
	test_get_redirect_length("<>  fuga   ");
	test_get_redirect_length("<<fuga   ");

	printf("--- test_get_envparam_length ---\n");
	test_get_envparam_length("$ENV");
	test_get_envparam_length("$ ENV");
	test_get_envparam_length("$ENV>hoge");
	test_get_envparam_length("$ENV  >hoge");
	test_get_envparam_length("$ENVfuga < fuga");
	test_get_envparam_length("$ENV|");

	printf("--- test_separate_redirect_word ---\n");
	test_separate_redirect_word("cd>hoge  ");
	test_separate_redirect_word("cd> hoge  ");
	test_separate_redirect_word("cd >hoge  ");
	test_separate_redirect_word("cd >   hoge fuga");
	test_separate_redirect_word("cd>>hoge  ");
	test_separate_redirect_word("cd>>>hoge  ");
	test_separate_redirect_word("cd> >hoge  ");
	test_separate_redirect_word("cd >hoge >>fuga <    aho ");
	test_separate_redirect_word("cd >hoge>>fuga   <aho <");

	initialize_env_list(env);
	printf("--- test_replace_env_param ---\n");
	test_replace_env_param("cd $HOME");
	test_replace_env_param("cd $HOME>test.txt");
	test_replace_env_param("cd '$HOME' $HOME");
	test_replace_env_param("cd $HOM HOME");
	test_replace_env_param("cd HOME");
	test_replace_env_param("echo $HOME $LANG");
	test_replace_env_param("echo $HOME '$LANG' $LANG");
	test_replace_env_param("echo $HOME$LANG2$HOME");
	test_replace_env_param("echo $HOME$LANG2$HOME");
	test_replace_env_param("echo \"'$HOME'\"'$LANG'$HOME");

	printf("--- memory leak check ---\n");
	system("leaks minishell");

	return (0);
}