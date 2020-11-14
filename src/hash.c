/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:20:09 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/08/13 23:45:21 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_hash(char *data)
{
	int	key;
	int	i;

	key = 0;
	i = 0;
	while (data[i])
	{
		key = key + data[i] * ft_pow(P, i);
		i++;
	}
	return (key % HTSIZE);
}

t_room		*ft_find_data(char *data)
{
	t_htable	*p;
	int			key;

	key = ft_hash(data);
	p = g_htable[key];
	while (p != NULL)
	{
		if (!ft_strcmp(p->rooms->name, data))
			return (p->rooms);
		p = p->next;
	}
	return (NULL);
}

void		ft_del_htable(void)
{
	int			i;
	t_htable	*ptr;
	t_htable	*tmp;

	i = 0;
	while (i < HTSIZE)
	{
		ptr = g_htable[i];
		while (ptr != NULL)
		{
			tmp = ptr->next;
			ft_del_room(&(ptr->rooms));
			free(ptr);
			ptr = tmp;
		}
		i++;
	}
}
