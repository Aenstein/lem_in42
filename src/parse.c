/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:35:22 by rretta            #+#    #+#             */
/*   Updated: 2020/08/13 22:37:48 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**ft_file_parse(char **split)
{
	char	tmp[4096 + 1];
	char	*str;
	char	*str2;
	int		len;

	str = "";
	str2 = "";
	while ((len = read(0, tmp, 4096)) > 0)
	{
		tmp[len] = '\0';
		if ((str2 = ft_strjoin(str, tmp)) == NULL)
			ft_exit("ERROR: STRJOIN ERROR");
		if (*str != '\0')
			free(str);
		str = str2;
	}
	if (len < 0)
		ft_exit("ERROR: INPUT FILE NAME");
	if ((split = ft_strsplit(str2, '\n')) == NULL)
		ft_exit("ERROR: SPLIT ERROR");
	if (ft_strstr(str2, "\n\n") != 0)
		ft_exit("ERROR: EMPTY LINE");
	ft_strdel(&str2);
	return (split);
}

int		ft_word_counter(char const *s, char c)
{
	int	q;

	q = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			q++;
		s++;
	}
	return (q);
}
