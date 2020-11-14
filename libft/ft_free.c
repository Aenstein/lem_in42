/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 04:20:10 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/02/07 04:20:27 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_free(void **mas, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(mas[i]);
		mas[i] = NULL;
		i++;
	}
	free(mas);
	mas = NULL;
	return (mas);
}
