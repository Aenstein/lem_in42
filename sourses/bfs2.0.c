/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs2.0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:19:51 by aenstein          #+#    #+#             */
/*   Updated: 2020/11/05 20:11:55 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

extern t_hasht			*g_hasht[HASHNUM];

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
	(lemin->bfs_lvl)++;
	while (edge)
	{
		table = g_hasht[edge->name[0]];
		while (table->room->name != edge->name)
			table = table->next;
		if (table->room->bfs_lvl == 0 && ft_strcmp(table->room->name,
			lemin->start->name))
		{
			table->room->bfs_lvl = lemin->bfs_lvl;
			push_queue(queue, create_elem(table->room));
		}
		edge = edge->next;
	}
}

/*static void		free_queue(t_queue **queue)
{
	t_queue 	*tmp;

	tmp = *queue;
	while (tmp)
	{
		tmp = tmp->next;
		free(*queue);
		*queue = tmp;
	}
}*/

void			bfs(t_lemin *lemin)
{
	t_queue		*queue;
	t_queue		*start;

	lemin->bfs_lvl = 0;
	push_queue(&queue, create_elem(lemin->start));
	start = queue;
	queue->room->bfs_lvl = lemin->bfs_lvl;
	while (queue)
	{
		if (ft_strcmp(queue->room->name, lemin->end->name))
			add_rooms(lemin, &queue, queue->room);
		else
			lemin->end->bfs_lvl = INT_MAX;
		queue = queue->next;
	}
	//free_queue(&start);
}