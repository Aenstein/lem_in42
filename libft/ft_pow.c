/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 19:12:32 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/14 21:33:34 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_pow(int x, unsigned int n)
{
	size_t	result;
	size_t	check;

	result = 1;
	while (n)
	{
		check = result;
		if (n & 1)
			result = result * (long double)x;
		x *= x;
		n = n >> 1;
		if (result < check)
			ft_printf("ERROR: overflow error\n");
	}
	return ((size_t)result);
}
