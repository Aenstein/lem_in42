/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:00:47 by aenstein          #+#    #+#             */
/*   Updated: 2020/11/05 20:11:27 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../lib/includes/header.h"
# define HASHNUM	(int)256

typedef struct	s_names
{
	char			*name1;
	char			*name2;
}				t_names;

typedef	struct	s_edge
{
	char			*name;
	int				weight;
	struct s_edge	*next;
	struct s_edge	*prev;
}				t_edge;

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	int				bfs_lvl;
	int				wave;
	int				ant_num;
	t_edge			*links;
}				t_room;

typedef struct	s_graph
{
	t_room			*start;
	t_room			*end;
}				t_graph;

typedef struct	s_lemin
{
	t_room			*start;
	t_room			*end;
	t_edge			*links;
	int				ants;
	int				bfs_lvl;
}				t_lemin;

typedef struct	s_hasht
{
	t_room			*room;
	struct s_hasht	*next;
}				t_hasht;

typedef struct	s_queue
{
	t_room			*room;
	struct s_queue	*next;
}				t_queue;

t_hasht			*g_hasht[HASHNUM];

void			bfs(t_lemin *lemin);
int				parse(t_lemin *lemin);
int				ft_isint(char *str);
int				countsplit(char **split);
void			parse_ants(t_lemin *lemin, char **line);
void			parse_rooms(t_lemin *lemin, char **line);
void			parse_edge(t_lemin *lemin, char **line);
char			*create_name(char *name);
#endif
