/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twodemint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 04:18:14 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/02/07 04:18:42 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			**ft_twodemint(size_t strlen, size_t maslen)
{
	int		**mas;
	size_t	i;

	mas = (int**)ft_memalloc(sizeof(int*) * maslen);
	if (mas == NULL)
		return (NULL);
	i = 0;
	while (i < maslen)
	{
		mas[i] = (int*)ft_memalloc(sizeof(int) * strlen);
		if (*mas == NULL)
			return ((int**)ft_free((void**)mas, i));
		i++;
	}
	return (mas);
}
