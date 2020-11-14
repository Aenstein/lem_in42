/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavel <pavel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:10:06 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/20 18:09:17 by pavel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static	size_t	ft_wordlen(const char *str, char c)
{
	size_t i;

	i = 0;
	while (str[i] != c && str[i] != 0)
		i++;
	return (i);
}

static	size_t	ft_lenarr(char *s, char c)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			i++;
		else
		{
			len++;
			i = i + ft_wordlen(s + i, c);
		}
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new_arr;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	new_arr = (char**)ft_memalloc(sizeof(char*) * (ft_lenarr((char*)s, c) + 1));
	if (new_arr == NULL)
		return (NULL);
	while (s[j] != 0)
	{
		if (s[j] == c)
			j++;
		else
		{
			new_arr[i] = (char*)ft_memalloc(ft_wordlen(s + j, c) + 1);
			if (new_arr[i] == NULL)
				return ((char**)ft_free((void**)new_arr, i));
			ft_strlcat(new_arr[i++], s + j, ft_wordlen(s + j, c) + 1);
			j = j + ft_wordlen(s + j, c);
		}
	}
	return (new_arr);
}
