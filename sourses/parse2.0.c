/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:49:36 by aenstein          #+#    #+#             */
/*   Updated: 2020/11/05 20:06:40 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

char	*create_name(char *name)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)ft_memalloc(sizeof(char) * ft_strlen(name) + 1)))
		exit(1);
	while (name[i] != '\0')
	{
		str[i] = name[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_isint(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	//if (str[i] == '0' && str[i + 1] != '\0')
	//	return (0);
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

int		countsplit(char **split)
{
	int		i;

	i = 0;
	while (split[i])
		i++;
	if (i == 3)
		return (1);
	else
		return (0);
}

int		parse(t_lemin *lemin)
{
	char	*line;

	parse_ants(lemin, &line);
	parse_rooms(lemin, &line);
	if (!(lemin->start) && !(lemin->end))
		exit(1);
	parse_edge(lemin, &line);
	return (0);
}