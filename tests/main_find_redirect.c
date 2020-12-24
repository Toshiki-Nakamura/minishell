#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "utils_redirect.h"
#include "utils_string_operation.h"

void	test_get_redirect_length(char *cmd)
{
	int ret = get_redirect_length(cmd);
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

void	test_skip_redirect_mark(char *cmd)
{
	t_redirection type;
	const char *ret = skip_redirect_mark(cmd, &type);
	printf("%s skip [%s](%d)\n", cmd, ret, type);
}

void	test_separate_redirect_info(char *cmd)
{
	t_redirection type;
	char *str = ft_strdup(cmd);
	separate_redirect_info(&str, &type);
	printf("%s include file name [%s](%d)\n", cmd, str, type);
	if (str)
		free(str);
}

int		main(void)
{
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

	printf("--- test_skip_redirect_mark ---\n");
	test_skip_redirect_mark(">test.txt");
	test_skip_redirect_mark(">   test.txt");
	test_skip_redirect_mark(">>  test.txt");
	test_skip_redirect_mark("<test.txt");
	test_skip_redirect_mark(">2test.txt");
	test_skip_redirect_mark("<&test.txt");
	test_skip_redirect_mark("><test.txt");
	test_skip_redirect_mark("<=test.txt");
	test_skip_redirect_mark(">& error.txt");
	test_skip_redirect_mark("<< error.txt");
	test_skip_redirect_mark("2>&1 error.txt");

	printf("--- test_separate_redirect_info ---\n");
	test_separate_redirect_info(">test.txt");
	test_separate_redirect_info(">   test.txt");
	test_separate_redirect_info(">>  test.txt");
	test_separate_redirect_info("<test.txt");
	test_separate_redirect_info(">2test.txt");
	test_separate_redirect_info("<&test.txt");
	test_separate_redirect_info("><test.txt");
	test_separate_redirect_info("<=test.txt");
	test_separate_redirect_info(">& error.txt");
	test_separate_redirect_info("<< error.txt");
	test_separate_redirect_info("2>&1 error.txt");

	printf("--- memory leak check ---\n");
	system("leaks minishell");

	return (0);
}