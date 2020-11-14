/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:29:27 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/13 22:41:06 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way_node		*ft_create_node(t_room *link_name)
{
	t_way_node	*tmp;

	tmp = NULL;
	if ((tmp = (t_way_node*)malloc(sizeof(t_way_node))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	tmp->name = link_name;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

t_edge			*ft_find_minus_two_link(t_edge *links)
{
	while (links != NULL)
	{
		if (links->weight == -2 && ft_find_data(links->name)->flag != -1)
			return (links);
		links = links->next;
	}
	return (NULL);
}

t_way			*ft_paste_node(t_way *way, t_way_node *node)
{
	t_way_node	*tmp;

	if (way == NULL)
	{
		if ((way = (t_way*)malloc(sizeof(t_way))) == NULL)
			ft_exit("MALLOC ERROR");
		way->way_length = 0;
		way->end_node = node;
		way->start_node = node;
		way->next = NULL;
		way->way_steps = 0;
		return (way);
	}
	tmp = way->end_node;
	while (tmp->prev)
		tmp = tmp->prev;
	tmp->prev = node;
	node->next = tmp;
	way->start_node = node;
	way->way_length++;
	way->next = NULL;
	return (way);
}

t_way			*ft_find_way(t_graph *g, t_room *room, t_edge *(*f) (t_edge *))
{
	t_edge		*link;
	t_way		*shortway;

	shortway = NULL;
	shortway = ft_paste_node(shortway, ft_create_node(room));
	if ((link = f(room->links)) == NULL)
		return (ft_del_way_return_null(&shortway));
	room = ft_find_data(link->name);
	shortway = ft_paste_node(shortway, ft_create_node(room));
	while (ft_strcmp(room->name, g->start->name))
	{
		if ((link = f(room->links)) == NULL)
			return (ft_del_way_return_null(&shortway));
		shortway = ft_paste_node(shortway, \
									ft_create_node(ft_find_data(link->name)));
		room = ft_find_data(link->name);
	}
	shortway->next = NULL;
	return (shortway);
}

t_way			*ft_del_way_return_null(t_way **way)
{
	t_way_node	*tmp;
	t_way_node	*ptr;
	t_way		*tmp_way;

	while (*way)
	{
		tmp_way = (*way)->next;
		tmp = (*way)->start_node;
		while (tmp != NULL)
		{
			ptr = tmp;
			tmp = tmp->next;
			ptr->name = NULL;
			free(ptr);
		}
		(*way)->end_node = NULL;
		free(*way);
		*way = NULL;
		*way = tmp_way;
	}
	return (NULL);
}
