/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:34:59 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/13 23:50:36 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_best_way(t_way *way1, t_way *way2, t_graph *g)
{
	if (way1 == NULL && way2 != NULL)
		return (0);
	if (way2 == NULL && way1 != NULL)
		return (1);
	way2->way_steps = ft_step_counter(way2, g);
	if (way1->way_steps <= way2->way_steps)
		return (1);
	return (0);
}

static void		ft_swap_way(t_way **left, t_way **right)
{
	t_way		*tmp;

	if ((tmp = (t_way*)ft_memalloc(sizeof(t_way))) == NULL)
		ft_exit("ERROR: INPUT ERROR");
	tmp->start_node = (*left)->start_node;
	tmp->end_node = (*left)->end_node;
	tmp->way_length = (*left)->way_length;
	(*left)->start_node = (*right)->start_node;
	(*left)->end_node = (*right)->end_node;
	(*left)->way_length = (*right)->way_length;
	(*right)->start_node = tmp->start_node;
	(*right)->end_node = tmp->end_node;
	(*right)->way_length = tmp->way_length;
	tmp->start_node = NULL;
	tmp->end_node = NULL;
	tmp->way_length = 0;
	ft_del_way_return_null(&tmp);
}

void			ft_sort_solution(t_way *way)
{
	t_way		*left;
	t_way		*right;

	left = way;
	right = way->next;
	while (left->next != NULL)
	{
		while (right)
		{
			if (left->way_length > right->way_length)
				ft_swap_way(&left, &right);
			right = right->next;
		}
		left = left->next;
		right = left->next;
	}
}

t_way			*ft_find_solution(t_room *room, t_graph *g)
{
	t_way		*solution;
	t_way		*head;

	solution = ft_find_way(g, room, ft_find_minus_one_link);
	head = solution;
	while (solution != NULL)
	{
		solution->next = ft_find_way(g, room, ft_find_minus_one_link);
		solution = solution->next;
	}
	ft_null(g);
	return (head);
}

t_way			*ft_solution(t_graph *g)
{
	t_way		*way1;
	t_way		*way2;

	way1 = ft_bhandari(g);
	way1->way_steps = ft_step_counter(way1, g);
	while ((way2 = ft_bhandari(g)) != NULL)
	{
		ft_sort_solution(way2);
		if (ft_best_way(way1, way2, g) == 1)
			ft_del_way_return_null(&way2);
		else
		{
			ft_del_way_return_null(&way1);
			way1 = way2;
		}
	}
	return (way1);
}
