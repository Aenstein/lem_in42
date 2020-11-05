/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_edges.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:16:49 by aenstein          #+#    #+#             */
/*   Updated: 2020/11/05 20:40:40 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

extern t_hasht			*g_hasht[HASHNUM];

void	ft_exist_name(t_hasht *tmp, char *name)
{
	while (ft_strcmp(tmp->room->name, name))
	{
		if (tmp->next == NULL)
			exit(1);
		tmp = tmp->next;
	}
	ft_strdel(&name);
}

void	ft_exist_link(t_edge *first, t_edge *second)
{
	if (first)
	{
		while (first->prev)
			first = first->prev;
		while (first->next)
			{
				if (!(ft_strcmp(first->name, second->name)))
					exit(1);
				else
					first = first->next;
			}
		if (!(ft_strcmp(first->name, second->name)))
			exit(1);
	}
}

void	ft_isedge(char *line, t_names *names)
{
	int		name_len;
	int		i;
	char	*tmp_name;
	t_hasht	*tmp;

	name_len = 1;
	i = -1;
	while (line[name_len] != '-' && line[name_len + 1] != '-')
		name_len++;
	if (!(tmp_name = (char *)ft_memalloc(sizeof(char) * name_len + 1)))
		exit(1);
	while (++i < name_len)
		tmp_name[i] = line[i];
	tmp_name[i] = '\0';
	tmp = g_hasht[tmp_name[0]];
	ft_exist_name(tmp, tmp_name);
	names->name1 = create_name(tmp_name);
	while (line[name_len] != '\0')
		name_len++;
	if (!(tmp_name = (char *)ft_memalloc(sizeof(char) * name_len - i + 1)))
		exit(1);
	name_len = i;
	i = -1;
	while (line[++name_len])
		tmp_name[++i] = line[name_len];
	tmp_name[name_len] = '\0';
	tmp = g_hasht[tmp_name[0]];
	ft_exist_name(tmp, tmp_name);
	names->name2 = create_name(tmp_name);
}

void	create_link(t_edge *first, t_edge *second)
{
	if (first)
	{
		first->next = second;
		second->prev = first;
	}
	else
		first = second;
}

void	create_edges(t_names *names)
{
	t_edge	*edge1;
	t_room	*room1;
	t_edge	*edge2;
	t_room	*room2;
	t_hasht	*tmp;

	if (!(edge1 = (t_edge *)ft_memalloc(sizeof(t_edge))))
		exit(1);
	edge1->name = create_name(names->name1);
	if (!(edge2 = (t_edge *)ft_memalloc(sizeof(t_edge))))
		exit(1);
	edge2->name = create_name(names->name2);
	tmp = g_hasht[edge1->name[0]];
	while (ft_strcmp(tmp->room->name, names->name1))
		tmp = tmp->next;
	ft_exist_link(tmp->room->links, edge2);
	while (ft_strcmp(tmp->room->name, names->name1))
		tmp = tmp->next;
	create_link(tmp->room->links, edge2);
	tmp = g_hasht[edge2->name[0]];
	while (ft_strcmp(tmp->room->name, names->name1))
		tmp = tmp->next;
	while (ft_strcmp(tmp->room->name, names->name1))
		tmp = tmp->next;
	create_link(tmp->room->links, edge1);
}

void	parse_edge(t_lemin *lemin, char **line)
{
	t_names		*names;

	names = (t_names *)ft_memalloc(sizeof(t_names)); // какая-то хуита с names, меняются значения строк
	ft_isedge(*line, names);
	create_edges(names);
	ft_strdel(line);
	ft_strdel(&names->name1);
	ft_strdel(&names->name2);
	while (get_next_line(0, line) > 0)
	{
		ft_isedge(*line, names);
		create_edges(names);
		ft_strdel(line);
		ft_strdel(&names->name1);
		ft_strdel(&names->name2);
	}
}
