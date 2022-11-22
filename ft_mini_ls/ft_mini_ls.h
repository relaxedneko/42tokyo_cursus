/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:26:05 by mabe              #+#    #+#             */
/*   Updated: 2020/12/04 22:02:23 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdio.h>
# include <string.h>

typedef struct	s_filelist
{
	char		*filename;
	long		time;
	long		nano_time;
}				t_filelist;

t_filelist		**count_file(t_filelist **lst, int *list_len);
int				dot_filter(char *filename);
t_filelist		**read_dir(t_filelist **lst);
t_filelist		*make_filelist(struct dirent *dent);
time_t			get_time(char *filename, int flag);
t_filelist		**sort_filelist(int len, t_filelist **lst);
void			put_result(t_filelist **lst, int len);
size_t			ft_strlen(const char *s);
int				put_error(int num);
#endif
