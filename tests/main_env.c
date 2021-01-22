#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "env_list_base.h"
#include "msutils_env_param.h"

void	test_get_envparam_length(char *cmd, int ans)
{
	int ret = get_envparam_length(cmd);
	if (ans == ret)
		printf("Test OK [%s]\n", cmd);
	else
		printf("Test NG [%s]: %d\n", cmd, ret);
}

void	test_replace_env_param(char *cmd)
{
	char *str = ft_strdup(cmd);
	replace_env_param(&str);
	printf("[%s] replaced [%s]\n", cmd, str);
	if (str)
		free(str);
}

void	test_is_invalid_env_name(const char *name, int ans)
{
	if (ans == is_invalid_env_name(name))
		printf("Test OK [%s]\n", name);
	else
		printf("Test NG [%s]\n", name);
}

int		main(int ac, char **av, char **env)
{
	(void)av;
	if (ac != 1)
		return (0);
	printf("--- test_get_envparam_length ---\n");
	test_get_envparam_length("$ENV", 4);
	test_get_envparam_length("$ ENV", 0);
	test_get_envparam_length("$ENV>hoge", 4);
	test_get_envparam_length("$ENV  >hoge", 4);
	test_get_envparam_length("$ENVfuga < fuga", 8);
	test_get_envparam_length("$ENV|", 4);

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
	test_replace_env_param("echo $?");

	printf("--- test_is_invalid_env_name ---\n");
	test_is_invalid_env_name("$HOGE", 1);
	test_is_invalid_env_name("$Hoge", 1);
	test_is_invalid_env_name("$H0G3", 1);
	test_is_invalid_env_name("$H_O_G_E", 1);
	test_is_invalid_env_name("$HO?GE", 0);
	test_is_invalid_env_name("$?HOGE", 0);
	test_is_invalid_env_name("$4HOGE", 0);
	test_is_invalid_env_name("$_HOGE", 0);
	test_is_invalid_env_name("$HO?ge", 0);
	test_is_invalid_env_name("HOGE=?", 1);
	test_is_invalid_env_name("Hooo=123", 1);

	printf("--- memory leak check ---\n");
	system("leaks minishell");
	return (0);
}