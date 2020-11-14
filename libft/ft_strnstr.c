/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:54:23 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/12 18:23:10 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;

	n = (size_t)ft_strlen((char *)needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len != 0 && n <= len)
	{
		if (*haystack == *needle)
			if (ft_memcmp(haystack, needle, n) == 0)
				return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
