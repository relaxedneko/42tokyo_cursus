/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:54:40 by mabe              #+#    #+#             */
/*   Updated: 2020/12/04 14:55:07 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

int		put_error(int num)
{
	if (num == 1)
		write(2, "Not accept command line arguments\n", 34);
	if (num == 2)
		write(2, "Memory allocation error\n", 24);
	if (num == 3)
		write(2, "Reading file status error\n", 26);
	return (-1);
}

int		main(int argc, char **argv)
{
	t_filelist	**lst;
	int			list_len;

	(void)argv;
	if (argc != 1)
		return (put_error(1));
	if (!(lst = (t_filelist **)malloc(1)))
		return (put_error(2));
	if (!(lst = count_file(lst, &list_len)))
		return (-1);
	if (!(read_dir(lst)))
		return (-1);
	sort_filelist(list_len, lst);
	put_result(lst, list_len);
	return (0);
}
