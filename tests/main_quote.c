#include <stdio.h>
#include "libft.h"
#include "utils_quote.h"

void	test_skip_to_next_quote(char *str)
{
	char *p = skip_to_next_quote(str);
	printf("%s -> %s\n", str, p);
}

int main(void)
{
	test_skip_to_next_quote("\"hoge\"fuga");
	test_skip_to_next_quote("'hoge'fuga");
	test_skip_to_next_quote("\"ho'ge\"fuga");
	test_skip_to_next_quote("'ho\"ge'fuga");
	test_skip_to_next_quote("'hogefuga");
	test_skip_to_next_quote("'hog\"efu\"ga");

	return (1);
}