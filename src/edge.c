/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:01:17 by rretta            #+#    #+#             */
/*   Updated: 2020/08/13 22:37:06 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_edge		*ft_creat_edge(char *name)
{
	t_edge	*ptr;

	if ((ptr = (t_edge*)ft_memalloc(sizeof(t_edge))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	if ((ptr->name = ft_strdup(name)) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	ptr->flag = 0;
	ptr->weight = 1;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}

void		ft_del_edge(t_edge *ptr)
{
	ft_strdel(&(ptr->name));
	free(ptr);
}

t_edge		*ft_find_edge1(t_room *from, t_room *to)
{
	t_edge	*link;

	link = from->links;
	while (ft_strcmp(to->name, link->name))
	{
		link = link->next;
		if (link == NULL)
			return (link);
	}
	return (link);
}
