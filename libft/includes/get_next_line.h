/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:27:05 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/02/11 03:55:16 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 1

typedef struct			s_my_list
{
	char				*content;
	int					file;
	struct s_my_list	*next;
}						t_my_list;

int						ft_intchr(char *str, char c, size_t len);
int						get_next_line(const int fd, char **line);
t_my_list				*ft_fdnew(int fd);
int						gnl(int fd, t_my_list **fd_line, char **line,
							char *str);
int						read_line(char **str, t_my_list **ptr_list,
							int num, size_t *len);

#endif
