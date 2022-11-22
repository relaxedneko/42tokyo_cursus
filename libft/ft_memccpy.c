/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:38:01 by mabe              #+#    #+#             */
/*   Updated: 2020/11/14 12:02:57 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ch_dst;
	unsigned char	*ch_src;
	size_t			i;

	ch_dst = (unsigned char *)dst;
	ch_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ch_dst[i] = ch_src[i];
		if (ch_src[i] == (unsigned char)c)
			return (dst + i + 1);
		else
			i++;
	}
	return (NULL);
}
