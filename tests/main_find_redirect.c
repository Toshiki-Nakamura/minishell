#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "redirect.h"
#include "utils_string_operation.h"

void	test_skip_redirect_mark(char *cmd)
{
	t_redirect_type type;
	const char *ret = skip_redirect_mark(cmd, &type);
	printf("%s skip [%s](%d)\n", cmd, ret, type);
}

void	test_get_redirect_length(char *cmd)
{
	int ret = get_redirect_length(cmd);
	printf("length(%d) in [%s]\n", ret, cmd);
}

void	test_separate_redirect_info(char *cmd)
{
	t_redirect_type type;
	char *str = ft_strdup(cmd);
	separate_redirect_info(&str, &type);
	printf("%s is separated (%d) and [%s]\n", cmd, type, str);
	if (str)
		free(str);
}

void	test_separate_redirect_word(char *cmd)
{
	char *word;
	char *str = ft_strdup(cmd);
	word = NULL;
	printf("[%s] separated\n", cmd);
	while (separate_redirect_word(&str, &word))
	{
		printf("\t[%s] and [%s]\n", str, word);
		if (word)
			free(word);
		//test_separate_redirect_word(str);
	}
	if (str)
		free(str);
}

int		main(void)
{
	printf("--- test_skip_redirect_mark ---\n");
	test_skip_redirect_mark("test.txt");
	test_skip_redirect_mark(">test.txt");
	test_skip_redirect_mark(">   test.txt");
	test_skip_redirect_mark(">>  test.txt");
	test_skip_redirect_mark(">>>  test.txt");
	test_skip_redirect_mark("<test.txt");
	test_skip_redirect_mark(">2test.txt");
	test_skip_redirect_mark("<&test.txt");
	test_skip_redirect_mark("><test.txt");
	test_skip_redirect_mark("<=test.txt");
	test_skip_redirect_mark(">& error.txt");
	test_skip_redirect_mark("<< error.txt");
	test_skip_redirect_mark("2>&1 error.txt");
	test_skip_redirect_mark(">test.txt<hoge.txt");

	printf("--- test_get_redirect_length ---\n");
	test_get_redirect_length("hoge");
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
	test_get_redirect_length("2>&1 fuga ");
	test_get_redirect_length("><");
	test_get_redirect_length(">    ");
	test_get_redirect_length(">>hoge>fuga<aho.txt");

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
	test_separate_redirect_info("2>&1 ");

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
	test_separate_redirect_word("cd >hoge>>fuga   2>&1 >aho.txt");

	//printf("--- memory leak check ---\n");
	//system("leaks minishell");

	return (0);
}