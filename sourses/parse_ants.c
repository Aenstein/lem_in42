/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:13:34 by aenstein          #+#    #+#             */
/*   Updated: 2020/11/10 16:57:32 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	parse_ants(t_lemin *lemin, char **line)
{
	get_next_line(lemin->fd, line);
	if (!(ft_isint(*line)))
		exit(1);
	lemin->ants = ft_atoi(*line);
	if (lemin->ants < 1)
	{
		ft_strdel(line);
		exit(1);
	}
	ft_strdel(line);
}
