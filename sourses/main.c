/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:01:40 by aenstein          #+#    #+#             */
/*   Updated: 2020/11/05 18:14:09 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdio.h>

int		main(void)
{
	t_lemin		*lemin;

	lemin = (t_lemin *)ft_memalloc(sizeof(t_lemin));
	parse(lemin);
	ft_printf("OK");
	return (0);
}
