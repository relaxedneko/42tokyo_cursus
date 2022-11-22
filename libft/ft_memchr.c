/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:53:20 by mabe              #+#    #+#             */
/*   Updated: 2020/11/14 13:11:18 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*ch_s;
	size_t			i;

	ch_s = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		if (ch_s[i] == (unsigned char)c)
			return ((void *)ch_s + i);
		else
			i++;
	}
	return (NULL);
}
