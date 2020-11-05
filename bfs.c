/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:13:52 by aenstein          #+#    #+#             */
/*   Updated: 2020/10/31 20:50:25 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_queue	*next_elem(t_queue **queue)
{
	t_queue		*elem;

	elem = NULL;
	if (queue && *queue)
	{
		elem = *queue;
		*queue = (*queue)->next;
	}
	return (elem);
}

static t_queue	*create_elem(t_room *room)
{
	t_queue		*queue;

	if (!(queue = (t_queue *)malloc(sizeof(t_queue))))
		return ; // exit
	queue->room = room;
	queue->next = NULL;
	return (queue);
}

static void		add_elem(t_queue **queue, t_queue *elem)
{
	t_queue		*current;
	
	if (queue && *queue)
	{
		current = *queue;
		while (current->next)
			current = current->next;
		current->next = elem;
	}
	else if (queue)
		*queue = elem;
}

static void		add_link(t_lemin *lemin, t_queue **queue, t_room *room)
{
	t_link		*current;
	
	current = lemin->links;
	while (current)
	{
		if (current->start == room)
		{
			if (current->end->bfs_lvl == -1)
			{
				current->end->bfs_lvl = room->bfs_lvl + 1;
				add_elem(queue, create_elem(current->end));
			}
		}
	}
}

void			bfs(t_lemin *lemin)
{
	t_queue		*queue;
	t_queue		*current;
	
	queue = NULL;
	// lem_in->start->bfs_lvl = 0;
	add_elem(&queue, create_elem(lemin->start));
	while (queue)
	{
		current = next_elem(&queue);
		if (current->room != lemin->end)
		{
			add_link(lemin, &queue, current->room);
			lemin->bfs_lvl = current->room->bfs_lvl;
		}
		else
			lemin->end->bfs_lvl = 99999999; // max int
		free(current);
	}
}