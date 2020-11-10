/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_edges2.0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:43:16 by aenstein          #+#    #+#             */
/*   Updated: 2020/11/10 16:57:32 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

extern t_hasht			*g_hasht[HASHNUM];

void	add_link(t_edge *start, t_edge *end)
{
	start->next = end;
	start->weight = 1;
	end->prev = start;
	end->weight = 1;
}

void	find_edge(t_room *start, t_room *end)
{
	t_edge	*start_link;
	t_edge	*end_link;
	t_edge	*tmp;

	//ft_printf ("line - %s-%s\n", start->name, end->name);
	start_link = (t_edge *)ft_memalloc(sizeof(t_edge));
	end_link = (t_edge *)ft_memalloc(sizeof(t_edge));
	start_link->name = create_name(end->name);
	end_link->name = create_name(start->name);
	if (start->links)
	{
		tmp = start->links;
		while (tmp->next)
			tmp = tmp->next;
		add_link(tmp, start_link);
	}
	else
	{
		start->links = start_link;
	}
	if (end->links)
	{
		tmp = end->links;
		while (tmp->next)
			tmp = tmp->next;
		add_link(tmp, end_link);
	}
	else
	{
		end->links = end_link;
	}
}

t_room	*find_room(char *start_name)
{
	t_hasht	*tmp;

	tmp = g_hasht[start_name[0]];
	while (ft_strcmp(start_name, tmp->room->name))
	{
		tmp = tmp->next;
		if (!(tmp))
			return (NULL);
	}
	return (tmp->room);
}

void	create_edge(char *line)
{
	char	*tmp;
	char	*start_name;
	char	*end_name;
	t_room	*start;
	t_room	*end;

	tmp = line;
	while ((tmp = ft_strchr(tmp + 1, '-')))
	{
		start_name = ft_strsub(line, 0, tmp - line);
		end_name = ft_strsub(tmp + 1, 0, ft_strlen(tmp + 1));
		start = find_room(start_name);
		end = find_room(end_name);
		ft_strdel(&start_name);
		ft_strdel(&end_name);
		if (start && end)
		{
			find_edge(start, end);
			return ;
		}
	}
	exit(1);
}

int		ft_iscomment(char *line)
{
	if (line[0] == '#')
		return (1);
	else
		return (0);
}

void	parse_edge(t_lemin *lemin, char **line)
{
	t_edge	*first;
	t_edge	*second;

	if (ft_iscomment(*line))
		ft_strdel(line);
	else
	{
		create_edge(*line);
		ft_strdel(line);
	}
	while (get_next_line(lemin->fd, line) > 0)
	{
		if (ft_iscomment(*line))
			ft_strdel(line);
		else
		{
			create_edge(*line);
			ft_strdel(line);
		}
	}
}