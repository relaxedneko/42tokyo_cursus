/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:28:30 by mabe              #+#    #+#             */
/*   Updated: 2020/12/13 16:06:25 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	err_case(char *s)
{
	free(s);
	s = NULL;
	return (-1);
}

int	put_line(char **next_buf, char **line)
{
	size_t	n;
	char	*tmp;
	int		ret;

	n = ft_strchr_len(*next_buf, '\n');
	if (n == 0)
		n = (ft_strlen(*next_buf)) + 1;
	if (!(tmp = ft_substr(*next_buf, 0, n - 1)))
		return (-1);
	free(*line);
	*line = tmp;
	tmp = NULL;
	ret = 0;
	if (ft_strchr_len(*next_buf, '\n') != 0)
	{
		if (!(tmp = ft_substr((*next_buf + n), 0, ft_strlen(*next_buf + n))))
			return (-1);
		ret = 1;
	}
	free(*next_buf);
	*next_buf = tmp;
	return (ret);
}

ssize_t	get_read(int fd, char **next_buf)
{
	char	*buf;
	char	*tmp;
	ssize_t	read_size;

	if (!(buf = (char *)malloc((size_t)BUFFER_SIZE + 1)))
		return (-1);
	if ((read_size = read(fd, buf, BUFFER_SIZE)) < 0)
		return (err_case(buf));
	buf[read_size] = '\0';
	if (!(tmp = ft_strjoin(*next_buf, buf)))
		return (err_case(buf));
	free(*next_buf);
	*next_buf = tmp;
	free(buf);
	buf = NULL;
	tmp = NULL;
	return (read_size);
}

int	get_next_line(int fd, char **line)
{
	static char	*next_buf;
	ssize_t		read_size;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	ret = 0;
	*line = NULL;
	while ((ft_strchr_len(next_buf, '\n') == 0))
	{
		read_size = get_read(fd, &next_buf);
		if (read_size == -1)
			return (-1);
		if (read_size == 0)
			break ;
	}
	ret = put_line(&next_buf, line);
	if (ret == 0)
		free(next_buf);
	return (ret);
}
