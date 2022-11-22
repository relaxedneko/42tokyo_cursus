/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:40:29 by mabe              #+#    #+#             */
/*   Updated: 2020/11/10 10:40:48 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ch_s1;
	unsigned char	*ch_s2;
	size_t			i;

	ch_s1 = (unsigned char *)s1;
	ch_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ch_s1[i] != ch_s2[i])
			return (ch_s1[i] - ch_s2[i]);
		else
			i++;
	}
	return (0);
}
