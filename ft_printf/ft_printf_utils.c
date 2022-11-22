/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:42:52 by mabe              #+#    #+#             */
/*   Updated: 2021/01/04 15:41:41 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		fill_zero_or_space(t_flags *flags, int put_flag, int len)
{
	int		i;
	char	*str;

	i = 0;
	if (0 < len)
	{
		if (!(str = (char *)malloc(len + 1)))
		{
			flags->putlen = -1;
			return (-1);
		}
		while (i < len)
		{
			if (put_flag == PUT_SPACE)
				str[i] = ' ';
			else if (put_flag == PUT_ZERO)
				str[i] = '0';
			i++;
		}
		str[i] = '\0';
		write(1, str, ft_strlen(str));
		free(str);
	}
	return (i);
}

void	put_nbr_handle(t_flags *flags, long long num, int *len)
{
	if (flags->format_char == 'd' || flags->format_char == 'u' ||
		flags->format_char == 'i')
		put_change_num(num, "0123456789", len, PUT_NUM);
	if (flags->format_char == 'x')
		put_change_num(num, "0123456789abcdef", len, PUT_NUM);
	if (flags->format_char == 'X')
		put_change_num(num, "0123456789ABCDEF", len, PUT_NUM);
}

int		put_minus(long long *num)
{
	int		i;

	i = 0;
	if (*num < 0)
	{
		write(1, "-", 1);
		*num *= -1;
		i += 1;
	}
	return (i);
}

void	put_change_num(long long num, char *set, int *count, int put_flag)
{
	int		base;

	base = ft_strlen(set);
	if (num < 0)
		num *= -1;
	if (num < (long long)base)
	{
		if (put_flag == PUT_NUM)
			write(1, &set[num], 1);
		*count += 1;
		return ;
	}
	put_change_num(num / base, set, count, put_flag);
	put_change_num(num % base, set, count, put_flag);
	return ;
}
