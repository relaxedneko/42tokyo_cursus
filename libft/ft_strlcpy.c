/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:59:51 by mabe              #+#    #+#             */
/*   Updated: 2020/11/08 10:39:34 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dst == NULL || src == NULL)
		return ((size_t)NULL);
	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i])
	{
		if (i < dstsize - 1)
			dst[i] = src[i];
		if (i == dstsize - 1)
			dst[i] = '\0';
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (i);
}
