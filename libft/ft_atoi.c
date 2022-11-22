/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 10:14:47 by mabe              #+#    #+#             */
/*   Updated: 2020/11/14 15:48:15 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		chk_long(unsigned long sum, int minus)
{
	if (sum >= LONG_MAX)
	{
		if (minus == 1)
			return (-1);
		else if (minus == -1 && sum - LONG_MAX >= 1)
			return (0);
	}
	return (sum * minus);
}

int				ft_atoi(const char *str)
{
	int				i;
	int				minus;
	unsigned long	sum;

	i = 0;
	minus = 1;
	sum = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (('0' <= str[i] && str[i] <= '9') && str[i] != '\0')
	{
		sum *= 10;
		sum += str[i] - '0';
		i++;
	}
	return (chk_long(sum, minus));
}
