/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:27:41 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/13 22:38:06 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*ft_creat_room(char *name, int x, int y)
{
	t_room		*tmp;

	if ((tmp = (t_room*)ft_memalloc(sizeof(t_room))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	tmp->name = ft_strdup(name);
	tmp->x = x;
	tmp->y = y;
	tmp->links = NULL;
	tmp->flag = 0;
	tmp->bf = INFINITY;
	tmp->bfs_level = -1;
	tmp->ants = 0;
	tmp->ant_id = 0;
	return (tmp);
}

t_htable		*ft_insert_room(t_room *room)
{
	t_htable	*p;
	t_htable	*p0;
	int			key;

	key = ft_hash(room->name);
	if ((p = (t_htable*)ft_memalloc(sizeof(t_htable))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	p0 = g_htable[key];
	g_htable[key] = p;
	p->next = p0;
	p->rooms = room;
	return (p);
}

void			ft_del_room(t_room **ptr)
{
	t_room		*room;
	t_edge		*edge;

	room = *ptr;
	if (room != NULL)
	{
		ft_strdel(&(room->name));
		while (room->links != NULL)
		{
			edge = room->links;
			room->links = room->links->next;
			ft_del_edge(edge);
		}
	}
	free(room);
	room = NULL;
}
