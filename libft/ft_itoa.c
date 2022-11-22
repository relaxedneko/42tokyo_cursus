/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:26:20 by mabe              #+#    #+#             */
/*   Updated: 2020/11/14 15:18:23 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(long nb)
{
	int		count;

	if (nb == 0)
		return (1);
	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*itoa;
	long	nb;
	int		digit;

	nb = n;
	digit = count_digit(nb);
	if (!(itoa = (char *)malloc(sizeof(char) * digit + 1)))
		return (NULL);
	itoa[digit] = '\0';
	if (nb == 0)
		itoa[0] = '0';
	if (nb < 0)
	{
		itoa[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		itoa[digit - 1] = (nb % 10) + '0';
		nb /= 10;
		digit--;
	}
	return (itoa);
}
