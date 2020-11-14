/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:23:54 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/02/18 20:29:56 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int			get_next_line(const int fd, char **line)
{
	static t_my_list	*ptr;
	char				*str;

	str = ft_strnew(1);
	if (fd < 0 || str == NULL)
		return (-1);
	return (gnl(fd, &ptr, line, str));
}

int			gnl(int fd, t_my_list **fd_line, char **line, char *str)
{
	int		num;
	int		rtn;
	size_t	len;

	len = 0;
	if (*fd_line == NULL)
	{
		if ((*fd_line = ft_fdnew(fd)) == NULL)
			return (-1);
	}
	else if ((*fd_line)->file != fd)
	{
		rtn = gnl(fd, &((*fd_line)->next), line, str);
		return (rtn);
	}
	if ((rtn = read_line(&str, fd_line, 0, &len)) == -1)
		return (-1);
	num = ft_intchr(str, '\n', ft_strlen(str));
	ft_strdel(&((*fd_line)->content));
	(*fd_line)->content = (num == -1) ? ft_strnew(1) : ft_strdup(str + num + 1);
	if (num != -1)
		*(str + num) = '\0';
	*line = str;
	return (rtn);
}

int			read_line(char **str, t_my_list **ptr_list, int num, size_t *len)
{
	int		end_line;
	char	str_read[BUFF_SIZE + 1];
	char	*tmp;
	char	*del;

	while ((end_line = read((*ptr_list)->file, str_read, BUFF_SIZE)) > 0)
	{
		str_read[end_line] = '\0';
		*len += end_line;
		if ((tmp = ft_strjoin(*str, str_read)) == NULL)
			return (-1);
		ft_strdel(str);
		*str = tmp;
		if ((num = ft_intchr(str_read, '\n', end_line)) != -1)
			break ;
	}
	if ((tmp = ft_strjoin((*ptr_list)->content, *str)) == NULL)
		return (-1);
	del = *str;
	*str = tmp;
	ft_strdel(&del);
	if (end_line < 0)
		return (-1);
	end_line = (end_line == 0 && ft_strlen(*str) == 0) ? 0 : 1;
	return (end_line);
}

t_my_list	*ft_fdnew(int fd)
{
	t_my_list *ptr;

	ptr = NULL;
	ptr = (t_my_list *)malloc(sizeof(t_my_list));
	if (ptr == NULL || fd < 0)
		return (NULL);
	ptr->content = ft_strnew(1);
	if (ptr->content == NULL)
	{
		free(ptr);
		return (NULL);
	}
	ptr->file = fd;
	ptr->next = NULL;
	return (ptr);
}

int			ft_intchr(char *str, char c, size_t len)
{
	size_t result;

	result = 0;
	while (str[result] != c && str[result])
		result++;
	return (result == len ? -1 : (int)result);
}
