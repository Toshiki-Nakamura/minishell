#include "../includes/minishell.h"

void	tab_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int		tab_size(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		ft_strncmp_ex(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			if ((unsigned char)s1[i] - (unsigned char)s2[i] != -32)
			{
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			}
		}
		i++;
	}
	return (0);
}
