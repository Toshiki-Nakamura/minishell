/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string_operation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:25:33 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/16 10:46:30 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_printable(char c, char *except)
{
	if ((' ' <= c) && (c <= '~'))
	{
		while (*except != 0)
		{
			if (*except++ == c)
				return (0);
		}
		return (1);
	}
	return (0);
}

char	*extract_word(const char *head, int cut_pos, int cut_len, char **word)
{
	char	*str;
	char	*cut;
	char	*ret;

	str = ft_strdup(head);
	if (!(*word = malloc(cut_len + 1)))
	{
		free(str);
		return (NULL);
	}
	cut = str + cut_pos;
	ft_strlcpy(*word, cut, cut_len + 1);
	*cut = '\0';
	ret = ft_strjoin(str, (cut + cut_len));
	free(str);
	return (ret);
}

char	*replace_word(const char *head, int cut_pos, int cut_len,
		const char *word)
{
	char	*str;
	char	*cut;
	char	*ret;
	int		length;

	str = ft_strdup(head);
	if (!word)
		word = "";
	length = ft_strlen(head) - cut_len + ft_strlen(word);
	if (!(ret = malloc(length + 1)))
	{
		free(str);
		return (NULL);
	}
	ret[0] = '\0';
	cut = str + cut_pos;
	ft_strlcat(ret, str, cut_pos + 1);
	ft_strlcat(ret, word, length + 1);
	ft_strlcat(ret, str + cut_pos + cut_len, length + 1);
	free(str);
	return (ret);
}
