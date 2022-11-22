/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:12:33 by mabe              #+#    #+#             */
/*   Updated: 2020/11/13 19:45:48 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**memory_free(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static int		count_char(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s && *s != c)
	{
		count++;
		s++;
	}
	return (count);
}

static char		**padding(char const *s, char **array, char c, int word_count)
{
	int		i;
	int		j;
	int		element_len;

	j = 0;
	while (j <= word_count - 1)
	{
		while (*s == c)
			s++;
		element_len = count_char(s, c);
		if (!(array[j] = (char *)malloc(sizeof(char) * element_len + 1)))
			return (memory_free(array));
		i = 0;
		while (i < element_len)
		{
			array[j][i] = *s;
			i++;
			s++;
		}
		array[j][i] = '\0';
		j++;
	}
	array[word_count] = NULL;
	return (array);
}

static int		word_counter(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s != '\0')
	{
		if (*s != c)
		{
			while (*s && *s != c)
				s++;
			count++;
		}
		else
			s++;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	char	**array;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = word_counter(s, c);
	if (!(array = (char **)malloc(sizeof(char *) * word_count + 1)))
		return (NULL);
	return (padding(s, array, c, word_count));
}
