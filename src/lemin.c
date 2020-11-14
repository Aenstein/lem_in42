/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:01:42 by rretta            #+#    #+#             */
/*   Updated: 2020/08/14 04:27:44 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

static t_graph	*init(void)
{
	t_graph		*g;

	if ((g = (t_graph*)ft_memalloc(sizeof(t_graph))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	g->v = 0;
	g->e = 0;
	return (g);
}

static void		ft_free_all(t_graph **g, t_way **way)
{
	free((*g)->edges);
	ft_del_way_return_null(way);
	ft_del_htable();
	free(*g);
	g = NULL;
}

int				main(void)
{
	char		**split;
	int			all;
	t_graph		*g;
	t_way		*ways;

	split = NULL;
	g = init();
	all = 0;
	split = ft_file_parse(split);
	while (split[all])
	{
		ft_printf("%s\n", split[all]);
		all++;
	}
	ft_printf("\n");
	g = ft_file_checker(split, all, g);
	ft_del_mas(&split, all);
	ways = ft_solution(g);
	ft_step_printer(ways, g);
	ft_free_all(&g, &ways);
	return (0);
}
