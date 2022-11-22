/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 10:23:16 by mabe              #+#    #+#             */
/*   Updated: 2020/11/10 15:21:43 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(join = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		join[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		join[i] = s2[i - s1_len];
		i++;
	}
	join[i] = '\0';
	return (join);
}
