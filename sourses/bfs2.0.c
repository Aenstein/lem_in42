/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs2.0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:19:51 by aenstein          #+#    #+#             */
/*   Updated: 2020/11/10 21:52:31 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

extern t_hasht			*g_hasht[HASHNUM];

static t_queue	*get_next(t_queue **queue)
{
	t_queue		*elem;
	
	elem = NULL;
	if (queue && *queue)
	{
		elem = (*queue);
		(*queue) = (*queue)->next;
	}
	return (elem);
}

static t_queue	*create_elem(t_room *room)
{
	t_queue		*tmp;

	if (!(tmp = (t_queue *)ft_memalloc(sizeof(t_queue))))
		exit (1);
	tmp->room = room;
	tmp->next = NULL;
	return (tmp);
}

static void		push_queue(t_queue **queue, t_queue *elem)
{
	t_queue *tmp;

	if (*queue && queue)
	{
		tmp = *queue;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	else if (queue)
		*queue = elem;
}

static void		add_rooms(t_lemin *lemin, t_queue **queue, t_room *room)
{
	t_edge		*edge;
	t_hasht		*table;

	edge = room->links;
	while (edge)
	{
		table = g_hasht[edge->name[0]];
		while (ft_strcmp(table->room->name,edge->name))
			table = table->next;
		if (table->room->bfs_lvl == 0 && ft_strcmp(table->room->name,
			lemin->start->name))
		{
			if (room->bfs_lvl >= 0)
				table->room->bfs_lvl = room->bfs_lvl + 1;
			else 
				table->room->bfs_lvl = -1; // возможно теряются некоторые ребра
			push_queue(queue, create_elem(table->room));
		}
		edge = edge->next;
	}
}

void			bfs(t_lemin *lemin)
{
	t_queue		*queue;
	t_queue		*tmp;
	t_edge		*edge;

	queue = NULL;
	lemin->bfs_lvl = 0;
	push_queue(&queue, create_elem(lemin->start));
	queue->room->bfs_lvl = lemin->bfs_lvl;
	while (queue)
	{
		/*edge = queue->room->links;
		while (edge->prev)
			edge = edge->prev;
		while (edge)
		{
			ft_printf("main - %s, link - %s\n", queue->room->name, edge->name);
			edge = edge->next;
		}*/
		tmp = get_next(&queue);
		if (tmp->room != lemin->end)
		{
			add_rooms(lemin, &queue, tmp->room);
			lemin->bfs_lvl = tmp->room->bfs_lvl;
		}
		else
		{
			tmp->room->bfs_lvl = -2;
			add_rooms(lemin, &queue, tmp->room);
			lemin->end->bfs_lvl = INT_MAX;
		}
		ft_printf("name - %s | bfs - %d\n", tmp->room->name, tmp->room->bfs_lvl);
	}
}
