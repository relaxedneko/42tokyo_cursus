/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:31:30 by mabe              #+#    #+#             */
/*   Updated: 2020/11/10 12:47:17 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ch_b;

	i = 0;
	ch_b = (unsigned char *)b;
	while (i < len)
	{
		ch_b[i] = (unsigned char)c;
		i++;
	}
	return ((void *)ch_b);
}
