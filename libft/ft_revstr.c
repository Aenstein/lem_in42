/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 20:03:23 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/03/14 20:03:42 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_revstr(char *str)
{
	size_t	i;
	size_t	len;
	char	buf;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		buf = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = buf;
		i++;
	}
	return (str);
}
