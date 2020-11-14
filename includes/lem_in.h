/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 04:30:57 by dima              #+#    #+#             */
/*   Updated: 2020/08/14 04:36:01 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdint.h>
# include <unistd.h>
# include "libft.h"
# include "libftprintf.h"

# define P				(int)10
# define HTSIZE 		(int)65536
# define INFINITY		INT32_MAX
# define ERROR_INPUT	"ERROR: ERROR INPUT"

typedef struct			s_edge
{
	char				*name;
	int					flag;
	int					weight;
	struct s_edge		*prev;
	struct s_edge		*next;
}						t_edge;

typedef struct			s_room
{
	char				*name;
	int					bfs_level;
	int					x;
	int					y;
	int					flag;
	t_edge				*links;
	int					bf;
	int					ant_id;
	int					ants;
}						t_room;

typedef struct			s_way_node
{
	t_room				*name;
	struct s_way_node	*next;
	struct s_way_node	*prev;
}						t_way_node;

typedef struct			s_way
{
	int					way_length;
	int					way_steps;
	struct s_way_node	*start_node;
	struct s_way_node	*end_node;
	struct s_way		*next;
}						t_way;

typedef struct			s_all_edges
{
	t_room				*u;
	t_room				*v;
	int					*w;
	int					*f;
}						t_all_edges;

typedef struct			s_graph
{
	int					ants;
	int					v;
	int					e;
	t_room				*start;
	t_room				*end;
	t_all_edges			*edges;
}						t_graph;

typedef struct			s_htable
{
	t_room				*rooms;
	struct s_htable		*next;
}						t_htable;

t_htable				*g_htable[HTSIZE];

char					**ft_file_parse(char **split);
t_graph					*ft_file_checker(char **split, int all, t_graph *g);
int						ft_val_ant(char *split);
int						ft_val_bond(char **lines, t_graph *g);
int						ft_val_room(char **split, t_graph *g, int i);
int						ft_val_coords(char *x, char *y);
char					***ft_val_links(char **split, int i, int all, \
																	t_graph *g);
int						ft_word_counter(char const *s, char c);
void					ft_exit(char *str);
void					ft_check_room(char **line, char *prev_line, t_graph *g);
void					ft_set_links(char ***links, int i, int all, t_graph *g);
t_edge					*ft_creat_edge(char *name);
void					ft_del_edge(t_edge *ptr);

t_room					*ft_creat_room(char *name, int x, int y);
t_room					*ft_add_push_back(t_room *tmp, char **split, int i);
void					ft_check_name_coord(t_room *ptr);
void					ft_print(t_room *tmp);
void					ft_del_room(t_room **ptr);

int						ft_hash(char *data);
t_htable				*ft_insert_room(t_room *room);
t_room					*ft_find_data(char *data);
void					ft_create_htable(int len);
void					ft_set_htable(char **split, int len);
void					ft_thprint(void);
void					ft_del_htable(void);

void					ft_print_bfs(void);

t_way_node				*ft_create_node(t_room *room_name);
t_edge					*ft_find_min_bfs_link(t_edge *links);
t_way					*ft_paste_first_node(t_way *way, t_way_node *node);
t_way					*ft_paste_node(t_way *way, t_way_node *node);
t_way					*ft_find_way(t_graph *g, t_room *room, \
											t_edge *(*func) (t_edge *link));
t_way					*ft_find_all_short_ways(t_way	*ways);
void					ft_print_way(t_way *way);
void					ft_bellman_ford(t_graph *g, t_room *start);

void					ft_insert_all_edges(char *u, char *v, int i, \
														t_all_edges **edges);
t_edge					*ft_find_edge1(t_room *from, t_room *to);
t_way					*ft_find_solution(t_room *room, t_graph *g);
t_edge					*ft_find_minus_one_link(t_edge *links);
void					ft_null(t_graph *g);
t_way					*ft_bhandari(t_graph *g);
t_way					*ft_solution(t_graph *g);
t_way					*ft_del_way_return_null(t_way **way);
int						ft_step_counter(t_way *ways, t_graph *g);
int						ft_step_printer(t_way *ways, t_graph *g);
t_edge					*ft_find_edge(t_room *from, t_room *to);
void					ft_del_mas(char ***mas, int len);
void					ft_sort_solution(t_way *way);
int						ft_find_short_way(t_graph *g, t_room *room, \
															t_room *prev_room);
void					ft_null_way(t_way *way);
t_edge					*ft_find_link(t_graph *g, t_room *room);

#endif
