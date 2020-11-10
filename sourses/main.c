/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:01:40 by aenstein          #+#    #+#             */
/*   Updated: 2020/11/10 20:59:18 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdio.h>

int		main(void)
{
	t_lemin		*lemin;
	t_way		*sss;
	int			fd;

	fd = open("test2", O_RDONLY);
	lemin = (t_lemin *)ft_memalloc(sizeof(t_lemin));
	lemin->fd = fd;
	parse(lemin);
	bfs(lemin);
	short_way(lemin);
	sss = lemin->short_w;
	while (sss)
	{
		ft_printf("%s(%d) - ", sss->room->name, sss->room->bfs_lvl);
		sss = sss->next;
	}
	//ft_printf("OK");*/
	return (0);
}
