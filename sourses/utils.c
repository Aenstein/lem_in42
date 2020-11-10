/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:17:31 by aenstein          #+#    #+#             */
/*   Updated: 2020/11/09 17:19:13 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	*ft_pmalloc(size_t size)
{
	unsigned char *mem;

	if (!(mem = (unsigned char *)malloc(size)))
		exit(1);
	else
		while (size)
			mem[--size] = 0;
	return ((void *)mem);
}