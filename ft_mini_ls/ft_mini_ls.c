/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:49:51 by mabe              #+#    #+#             */
/*   Updated: 2020/12/04 22:03:23 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

int			dot_filter(char *filename)
{
	if (*filename == '.')
		return (0);
	else
		return (1);
}

time_t		get_time(char *filename, int flag)
{
	struct stat	*buf;
	long		time;

	if (!(buf = (struct stat *)malloc(sizeof(struct stat))))
	{
		put_error(2);
		return (-1);
	}
	if (lstat(filename, buf) == -1)
		return (-1);
	else if (flag == 0)
		time = (long)(buf->st_mtimespec).tv_sec;
	else if (flag == 1)
		time = (long)(buf->st_mtimespec).tv_nsec;
	free(buf);
	buf = NULL;
	return (time);
}

t_filelist	*make_filelist(struct dirent *dent)
{
	t_filelist	*new;

	if (!(new = (t_filelist *)malloc(sizeof(t_filelist))))
		return (NULL);
	new->filename = dent->d_name;
	new->time = get_time(new->filename, 0);
	new->nano_time = get_time(new->filename, 1);
	if (new->time == -1 || new->nano_time == -1)
	{
		put_error(3);
		return (NULL);
	}
	return (new);
}

t_filelist	**read_dir(t_filelist **lst)
{
	DIR				*dir;
	struct dirent	*dent;
	int				i;

	i = 0;
	if (!(dir = opendir(".")))
	{
		perror("error");
		return (NULL);
	}
	while ((dent = readdir(dir)) != NULL)
	{
		if (dot_filter(dent->d_name) == 1)
		{
			lst[i] = make_filelist(dent);
			i++;
		}
	}
	closedir(dir);
	return (lst);
}

t_filelist	**count_file(t_filelist **lst, int *list_len)
{
	DIR				*dir;
	struct dirent	*dent;
	int				i;

	i = 0;
	if (!(dir = opendir(".")))
	{
		perror("error");
		return (NULL);
	}
	while ((dent = readdir(dir)) != NULL)
	{
		if (dot_filter(dent->d_name) == 1)
			i++;
	}
	free(lst);
	if (!(lst = (t_filelist **)malloc(sizeof(t_filelist *) * i)))
	{
		put_error(2);
		return (NULL);
	}
	*list_len = i;
	closedir(dir);
	return (lst);
}
