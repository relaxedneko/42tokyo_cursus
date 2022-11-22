/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:08:36 by mabe              #+#    #+#             */
/*   Updated: 2020/11/14 15:03:21 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		chkchar(char const *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*trimstr;
	size_t	trim_len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1)
	{
		if (chkchar(set, *s1) == 1)
			s1++;
		else
			break ;
	}
	trim_len = ft_strlen(s1) - 1;
	while (trim_len > 0)
	{
		if (chkchar(set, s1[trim_len]) == 1)
			trim_len--;
		else
			break ;
	}
	if (*s1 == '\0')
		trimstr = ft_strdup(s1);
	else
		trimstr = ft_substr((char *)s1, 0, trim_len + 1);
	return (trimstr);
}
