/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:42:54 by aenstein          #+#    #+#             */
/*   Updated: 2020/10/17 15:21:36 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	parse_room(t_lemin *lemon, char *str)
{
		
}

void	parse_ants(t_lemin *lemin, char *str)
{
	lemin->ants = ft_atoi(str);
	if (lemin->ants < 1)
		return ; // exit
}

void	parse_rooms(t_lemin *lemin, char **str)
{
	int		i;
	int		j;
	char	**line;

	i = 1;
	while (str[i])
	{
		if (ft_strcmp(str[i], "##start"))
		{
			parse_room(lemin, str[i + 1]);
			i += 2;
		}
		if (ft_strcmp(str[i], "##end"))
		{
			parse_room(lemin, str[i + 1]);
			i += 2;
		}
		else
		{
			parse_room(lemin, str[i]);
			i++;
		}
	}
}

int		parse(t_lemin *lemin)
{
	char	*line;
	char	**line_split;

	line = ft_read_stream(0);
	line_split = ft_str_split_str(line, "\n");
	ft_strdel(&line);
	parse_ants(lemin, line_split[0]);
	parse_rooms(lemin, line_split);
	return (0);
}