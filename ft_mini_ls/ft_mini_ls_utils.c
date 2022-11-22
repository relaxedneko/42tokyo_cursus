/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:54:08 by mabe              #+#    #+#             */
/*   Updated: 2020/12/04 22:01:42 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

size_t		ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void		put_result(t_filelist **lst, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		write(1, lst[i]->filename, ft_strlen(lst[i]->filename));
		write(1, "\n", 1);
		i++;
	}
}

void		sort_sametime(t_filelist **lst1, t_filelist **lst2, int *i)
{
	t_filelist	*tmp;

	if ((*lst1)->nano_time > (*lst2)->nano_time)
	{
		tmp = *lst1;
		*lst1 = *lst2;
		*lst2 = tmp;
		*i = 0;
	}
	else if (((*lst1)->nano_time == (*lst2)->nano_time) &&
			(ft_strcmp((*lst1)->filename, (*lst2)->filename) > 0))
	{
		tmp = *lst1;
		*lst1 = *lst2;
		*lst2 = tmp;
		*i = 0;
	}
	*i += 1;
}

t_filelist	**sort_filelist(int len, t_filelist **lst)
{
	int			i;
	int			flag;
	t_filelist	*tmp;

	i = 0;
	flag = 0;
	while (i < len - 1)
	{
		if (lst[i]->time > lst[i + 1]->time)
		{
			tmp = lst[i];
			lst[i] = lst[i + 1];
			lst[i + 1] = tmp;
			i = 0;
		}
		else if (lst[i]->time == lst[i + 1]->time)
			sort_sametime(&lst[i], &lst[i + 1], &i);
		else
			i++;
	}
	return (lst);
}
