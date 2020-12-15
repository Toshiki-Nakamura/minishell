#include <stdio.h>
#include "env_list_base.h"
#include "utils_redirect.h"
#include "utils_env_param.h"
#include "utils_string_operation.h"

void	test_get_redirect_length(char *cmd)
{
	int ret = get_redirect_length(cmd);
	printf("%d <= %s\n", ret, cmd);
}

void	test_get_envparam_length(char *cmd)
{
	int ret = get_envparam_length(cmd);
	printf("%d <= %s\n", ret, cmd);
}

void	test_extract_redirect_word(char *cmd)
{
	char *word;
	char *ret = extract_redirect_word(cmd, &word);
	printf("%s => %s:[%s]\n", cmd, word, ret);
}

void	test_replace_env_param(char *cmd)
{
	char *ret = replace_env_param(cmd);
	printf("%s => %s\n", cmd, ret);
}

int		main(int ac, char **av, char **env)
{
	(void)av;
	if (ac != 1)
		return (0);
	initialize_env_list(env);

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

	test_get_envparam_length("$ENV");
	test_get_envparam_length("$ ENV");
	test_get_envparam_length("$ENV>hoge");
	test_get_envparam_length("$ENV  >hoge");
	test_get_envparam_length("$ENVfuga < fuga");
	test_get_envparam_length("$ENV|");

	test_extract_redirect_word("cd>hoge  ");
	test_extract_redirect_word("cd> hoge  ");
	test_extract_redirect_word("cd >hoge  ");
	test_extract_redirect_word("cd >   hoge fuga");
	test_extract_redirect_word("cd>>hoge  ");
	test_extract_redirect_word("cd>>>hoge  ");
	test_extract_redirect_word("cd> >hoge  ");

	test_replace_env_param("cd $HOME");
	test_replace_env_param("cd $HOME>test.txt");
	test_replace_env_param("cd '$HOME' $HOME");
	test_replace_env_param("cd $HOM HOME");

	return (0);
}