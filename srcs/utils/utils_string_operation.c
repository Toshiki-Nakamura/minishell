/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string_operation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:25:33 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/24 21:11:00 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*extract_word(const char *head, int cut_pos, int cut_len, char **word)
{
	char	*str;
	char	*cut;
	char	*ret;

	if (!head || !word)
		return (NULL);
	if (!(str = ft_strdup(head)))
		return (NULL);
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

	if (!(str = ft_strdup(head)))
		return (NULL);
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
