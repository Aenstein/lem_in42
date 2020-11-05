/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:15:28 by aenstein          #+#    #+#             */
/*   Updated: 2020/11/05 20:12:10 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

extern t_hasht			*g_hasht[HASHNUM];

int		ft_isroom(char *line)
{
	char	**split;

	split = NULL;
	if (!(ft_strcmp(line, "##start")))
		return (2);
	else if (!(ft_strcmp(line, "##end")))
		return (3);
	if (!(ft_strncmp(line, "#", 1)))
		return (4);
	split = ft_strsplitstr(line, " ");
	if (countsplit(split) && ft_isint(split[0]) && ft_isint(split[1]) &&
		ft_isint(split[2]))
	{
		free(split);
		return (1);
	}
	else
	{
		free(split);
		return (0);
	}
}

t_room	*create_room(char **split)
{
	t_room	*room;
	t_hasht	*tmp;
	t_hasht *element;

	if (!(strncmp(split[0], "L", 1)))
		exit(1);
	if (!(room = (t_room *)ft_memalloc(sizeof(t_room))))
		exit(1);
	room->name = create_name(split[0]);
	room->x = ft_atoi(split[1]);
	room->y = ft_atoi(split[0]);
	element = (t_hasht *)ft_memalloc(sizeof(t_hasht));
	element->room = room;
	if (g_hasht[split[0][0]])
	{
		tmp = g_hasht[split[0][0]];
		while (tmp->next) // добавить проверку первого элемента
		{
			if (!(ft_strcmp(tmp->room->name, room->name)))
				exit(1);
			tmp = tmp->next;
		}
		tmp->next = element;
	}
	else
		g_hasht[split[0][0]] = element;
	free(split);
	return (room);		
}

void	parse_rooms(t_lemin *lemin, char **line)
{
	char	**split;
	int		i;

	split = NULL;
	while (get_next_line(0, line) > 0 && (i = ft_isroom(*line)))
	{
		if (i == 2 || i == 3)
		{
			ft_strdel(line);
			if (get_next_line(0, line) > 0 && (ft_isroom(*line) == 1))
				split = ft_strsplitstr(*line, " ");
			else
				exit(1);
			if (i == 2 && !(lemin->start))
				lemin->start = create_room(split);
			else if (i == 3 && !(lemin->end))
				lemin->end = create_room(split);
			else
				exit(1);
		}
		else if (ft_isroom(*line) == 1)
			create_room(ft_strsplitstr(*line, " "));
		if (ft_isroom(*line) == 0)
			exit(1);
		ft_strdel(line);
	}
}
