/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bellman_ford.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 20:51:24 by rretta            #+#    #+#             */
/*   Updated: 2020/08/13 22:39:28 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		bf_reset(void)
{
	t_htable	*tmp;
	int			i;

	i = 0;
	while (i < HTSIZE)
	{
		tmp = g_htable[i];
		while (tmp)
		{
			tmp->rooms->bf = INFINITY;
			tmp = tmp->next;
		}
		i++;
	}
}

void			ft_bellman_ford(t_graph *g, t_room *start)
{
	int			i;
	int			j;
	t_room		*u;
	t_room		*v;

	i = -1;
	bf_reset();
	start->bf = 0;
	while (++i < g->v - 1)
	{
		j = 0;
		while (j < g->e)
		{
			u = g->edges[j].u;
			v = g->edges[j].v;
			if (*(g->edges[j].w) == -2 || *(g->edges[j].w) == -3)
			{
				j++;
				continue ;
			}
			if (u->bf != INFINITY && v->bf > u->bf + *(g->edges[j].w))
				v->bf = u->bf + *(g->edges[j].w);
			j++;
		}
	}
}

void			ft_insert_all_edges(char *u, char *v, int i, \
														t_all_edges **edges)
{
	t_edge		*link;

	link = ft_find_data(u)->links;
	while (ft_strcmp(link->name, v))
		link = link->next;
	(*edges)[i].u = ft_find_data(u);
	(*edges)[i].v = ft_find_data(v);
	(*edges)[i].w = &(link->weight);
	(*edges)[i].f = &(link->flag);
	link = ft_find_data(v)->links;
	while (ft_strcmp(link->name, u))
		link = link->next;
	(*edges)[i + 1].v = ft_find_data(u);
	(*edges)[i + 1].u = ft_find_data(v);
	(*edges)[i + 1].w = &(link->weight);
	(*edges)[i + 1].f = &(link->flag);
}
