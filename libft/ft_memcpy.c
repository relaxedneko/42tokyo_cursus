/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:50:39 by mabe              #+#    #+#             */
/*   Updated: 2020/11/07 13:19:24 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*ch_dst;
	const unsigned char		*ch_src;
	size_t					i;

	if (n == 0 || (dst == NULL && src == NULL))
		return (dst);
	ch_dst = (unsigned char *)dst;
	ch_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ch_dst[i] = ch_src[i];
		i++;
	}
	return (dst);
}
