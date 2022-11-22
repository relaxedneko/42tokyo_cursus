/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_formats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:42:41 by mabe              #+#    #+#             */
/*   Updated: 2021/01/14 11:57:47 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	chk_prec(t_flags *flags, long long *ret)
{
	if (*ret >= INT_MAX)
		*ret = INT_MAX;
	if (flags->prec_input == 0 && *ret == 0)
		flags->prec_input = -1;
	return ;
}

void	catch_prec(va_list *ap, t_flags *flags, const char ***format, int *len)
{
	long long	ret;

	ret = 0;
	if (***format == '-')
	{
		flags->putlen += flag_case_handle(ap, &**format, *len);
		return ;
	}
	if (***format == '*')
	{
		ret = (int)va_arg(*ap, int);
		flags->prec_input = 1;
		**format += 1;
	}
	while ('0' <= ***format && ***format <= '9')
	{
		ret *= 10;
		ret += ***format - '0';
		flags->prec_input = 1;
		**format += 1;
	}
	chk_prec(flags, &ret);
	flags->prec = (int)ret;
	return ;
}

void	asterisk_width(va_list *ap, const char *format, long long *ret, int *i)
{
	if ((format[*i] == ' ' && format[*i + 1] == '*'))
	{
		write(1, " ", 1);
		*i += 1;
	}
	if (format[*i] == '*')
	{
		*ret = (int)va_arg(*ap, int);
		*i += 1;
	}
}

int		catch_width(va_list *ap, t_flags *flags, const char *format)
{
	int			i;
	long long	ret;

	i = 0;
	ret = 0;
	asterisk_width(ap, format, &ret, &i);
	while ('0' <= format[i] && format[i] <= '9')
	{
		ret *= 10;
		ret += format[i] - '0';
		i++;
	}
	if (ret < 0)
	{
		flags->flag_left = 1;
		if (flags->flag_zero == 1)
			flags->flag_zero = 0;
		ret *= -1;
	}
	if (ret >= INT_MAX)
		ret = INT_MAX;
	flags->field_width = (int)ret;
	return (i);
}

int		catch_flags(t_flags *flags, const char *format)
{
	int		i;

	i = 0;
	while (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '-')
			flags->flag_left = 1;
		if (format[i] == '0')
			flags->flag_zero = 1;
		i++;
	}
	if (flags->flag_left == 1 && flags->flag_zero == 1)
		flags->flag_zero = 0;
	return (i);
}
