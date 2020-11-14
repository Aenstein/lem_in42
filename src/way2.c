/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:29:27 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/14 04:25:41 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_edge			*ft_find_min_bfs_link(t_edge *links)
{
	int			minbf;
	t_room		*room;
	t_edge		*minbflink;

	minbf = INFINITY;
	while (links != NULL)
	{
		room = ft_find_data(links->name);
		if (minbf > room->bf && links->weight != -1 && \
									room->flag != -1 && links->weight != -3)
		{
			minbf = room->bf;
			minbflink = links;
		}
		links = links->next;
	}
	if (minbf == INT32_MAX)
		return (NULL);
	return (minbflink);
}

static int		ft_find_back(t_graph *g, t_room *room, char *prev_room)
{
	t_edge		*links;
	t_room		*tmp;

	links = room->links;
	while (links)
	{
		tmp = ft_find_data(links->name);
		if (links->weight == -2 && ft_strcmp(prev_room, links->name))
		{
			if (ft_find_short_way(g, tmp, room))
			{
				ft_find_edge(tmp, room)->weight = -2;
				return (1);
			}
		}
		links = links->next;
	}
	return (0);
}

static int		ft_check_room_in_way(t_room *room, char *prev_room)
{
	t_edge		*links;

	links = room->links;
	while (links)
	{
		if (links->weight == -1 && ft_strcmp(links->name, prev_room) && \
										ft_find_data(links->name)->flag != -1)
			return (1);
		links = links->next;
	}
	return (0);
}

static int		ft_find_forward(t_graph *g, t_room *room, t_room *prev_room)
{
	t_edge		*link;
	t_room		*next_room;

	while (1)
	{
		if (!(link = ft_find_min_bfs_link(room->links)))
			break ;
		next_room = ft_find_data(link->name);
		if (ft_strcmp(room->name, g->end->name) && \
								ft_check_room_in_way(room, prev_room->name))
		{
			ft_find_edge(prev_room, room)->weight = -3;
			ft_find_edge(room, prev_room)->weight = -3;
			room->flag = 0;
			return (0);
		}
		if (ft_find_short_way(g, next_room, room))
		{
			ft_find_edge(next_room, room)->weight = -2;
			if (ft_find_edge(room, next_room)->weight != -2)
				ft_find_edge(room, next_room)->weight = -1;
			return (1);
		}
	}
	return (0);
}

int				ft_find_short_way(t_graph *g, t_room *room, t_room *prev_room)
{
	if (room->flag == -1)
		return (0);
	if (room == g->start)
		return (1);
	room->flag = -1;
	if (ft_find_back(g, room, prev_room->name))
		return (1);
	if (ft_find_forward(g, room, prev_room))
		return (1);
	return (0);
}
