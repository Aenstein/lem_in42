/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:14:02 by aenstein          #+#    #+#             */
/*   Updated: 2020/11/10 20:14:26 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*t_room	*find_room(char *name)
{
	t_hasht	*cur;

	cur = g_hasht[name[0]];
	while (ft_strcmp(cur->room->name, name))
		cur = cur->next;
	return (cur->room);
}*/

t_room	*find_min_bfs(t_room *room)
{
	t_edge	*edge;
	t_room	*tmp;
	t_room	*cur;
	int		bfs;

	edge = room->links;
	while (edge->prev)
		edge = edge->prev;
	tmp = find_room(edge->name);
	bfs = room->bfs_lvl;
	if (edge->next)
		while (edge)
		{
			tmp = find_room(edge->name);
			if (bfs > tmp->bfs_lvl && tmp->bfs_lvl >= 0)
			{
				bfs = tmp->bfs_lvl;
				cur = tmp;
			}
			edge = edge->next;
		}
	else
	{
		tmp = find_room(edge->name);
		cur = tmp;
	}
	return (cur);
}

void	create_new_node(t_way *way, t_room *room)
{
	t_way *new;

	new = (t_way *)ft_pmalloc(sizeof(t_way));
	new->room = room;
	way->prev = new;
	new->next = way;
}

void	change_waight(t_room *prev, t_room *next)
{
	t_edge	*tmp;
	
	tmp = next->links;
	while (tmp->prev)
		tmp = tmp->prev;
	while (ft_strcmp(tmp->name, prev->name))
		tmp = tmp->next;
	tmp->weight = -1;
	tmp = prev->links;
	while (tmp->prev)
		tmp = tmp->prev;
	while (ft_strcmp(tmp->name, next->name))
		tmp = tmp->next;
	tmp->weight = INT_MAX;
}

void	short_way(t_lemin *lemin)
{
	t_way	*way;
	t_way	*cur;
	t_room	*tmp;

	way = (t_way *)ft_pmalloc(sizeof(t_way));
	way->room = find_room(lemin->end->name); //lemin->end;
	cur = way;
	while (cur && ft_strcmp(cur->room->name, lemin->start->name))
	{
		tmp = find_min_bfs(cur->room);
		create_new_node(cur, tmp);
		change_waight(cur->prev->room, cur->room);
		cur = cur->prev;
	}
	lemin->short_w = cur;
}