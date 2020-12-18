#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void	sig_hundle(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		write(1, "$> ", 3);

	}
	if (signum == SIGQUIT)
	{
		write(1,"\nSIGNAL is CTRL-\\ \n", 19);
		exit(0);
	}
}

void	prompt()
{
	char buf;
	int ret;
	while ((ret = read(0, &buf, 1)) > 0)
	{
		if (buf == '\n')
			break ;
	}
	if (!ret)     // ctrl-DでEOFになる
		write(1, "EOF!!!", 6);
}

int		main()
{
	signal(SIGINT, sig_hundle); // "ctrl-C"で実行
	signal(SIGQUIT, sig_hundle); // "ctrl-\"で実行
	while (1)
	{
		write(1, "$> ", 3);
		prompt();
	}
}
