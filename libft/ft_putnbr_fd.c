/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:30:20 by mabe              #+#    #+#             */
/*   Updated: 2020/11/12 13:45:03 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		c = n % 10 + '0';
		write(fd, &c, 1);
	}
	if (n < 10)
	{
		c = n % 10 + '0';
		write(fd, &c, 1);
	}
}
