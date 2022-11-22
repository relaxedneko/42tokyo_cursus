/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:53:07 by mabe              #+#    #+#             */
/*   Updated: 2020/11/15 10:27:41 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!needle[0])
		return ((char *)s);
	i = 0;
	while (s[i] && i < len)
	{
		j = 0;
		if (s[i] == needle[j])
		{
			while (needle[j] && s[i + j] == needle[j] && i + j < len)
			{
				j++;
				if (needle[j] == '\0')
					return ((char *)s + i);
			}
		}
		i++;
	}
	return (NULL);
}
