/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bhandari.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:04:29 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/13 22:39:10 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_edge		*ft_find_edge(t_room *from, t_room *to)
{
	t_edge	*link;

	link = from->links;
	while (link)
	{
		if (!ft_strcmp(to->name, link->name))
			return (link);
		link = link->next;
	}
	return (link);
}

t_edge		*ft_find_minus_one_link(t_edge *links)
{
	while (links != NULL)
	{
		if (links->weight == -1 && links->flag != -1)
			break ;
		links = links->next;
	}
	if (links != NULL)
		links->flag = -1;
	return (links);
}

void		ft_null(t_graph *g)
{
	int		i;

	i = 0;
	while (i < g->e)
		*(g->edges[i++].f) = 0;
}

void		ft_null_way(t_way *way)
{
	t_way		*tmp;
	t_way_node	*node;

	tmp = way;
	while (tmp)
	{
		node = tmp->start_node;
		while (node)
		{
			node->name->flag = 0;
			node = node->next;
		}
		tmp = tmp->next;
	}
}

t_way		*ft_bhandari(t_graph *g)
{
	t_way	*tmp;

	tmp = NULL;
	ft_bellman_ford(g, g->start);
	if (ft_find_short_way(g, g->end, g->end))
		tmp = ft_find_solution(g->end, g);
	ft_null_way(tmp);
	return (tmp);
}
