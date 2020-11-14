/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:36:31 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/13 22:37:54 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_print_way(t_way *way)
{
	t_way_node	*node;

	node = way->start_node;
	while (node != NULL)
	{
		ft_printf("%s ", node->name->name);
		node = node->next;
	}
	ft_printf("len = %d\n", way->way_length);
}

void		ft_print(t_room *tmp)
{
	t_edge	*ptr;

	ft_printf("name = %s bf = %d x = %d y = %d\n", tmp->name, tmp->bf, \
															tmp->x, tmp->y);
	ptr = tmp->links;
	while (ptr != NULL)
	{
		ft_printf("link name = %s; ", ptr->name);
		ptr = ptr->next;
	}
	ft_putchar('\n');
}

void		ft_thprint(void)
{
	t_htable	*ptr;
	int			i;

	i = 0;
	while (i < HTSIZE)
	{
		ptr = g_htable[i];
		if (ptr != NULL)
		{
			while (ptr != NULL)
			{
				ft_print(ptr->rooms);
				ptr = ptr->next;
			}
		}
		i++;
	}
}

void		ft_print_bfs(void)
{
	t_htable	*tmp;
	int			i;

	i = 0;
	while (i < HTSIZE)
	{
		tmp = g_htable[i];
		while (tmp)
		{
			ft_printf("BF LEVEL = %d, BF = %d, ROOM = %s flag = %d\n", \
										tmp->rooms->bfs_level, tmp->rooms->bf, \
											tmp->rooms->name, tmp->rooms->flag);
			tmp = tmp->next;
		}
		i++;
	}
}
