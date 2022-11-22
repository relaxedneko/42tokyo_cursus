/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_s_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:45:26 by mabe              #+#    #+#             */
/*   Updated: 2021/01/15 13:57:27 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	case_percent_sign(t_flags *flags)
{
	int		i;

	i = 0;
	if (flags->flag_left == 0)
	{
		if (flags->flag_zero == 0)
			i += fill_zero_or_space(flags, PUT_SPACE, (flags->field_width - 1));
		else
			i += fill_zero_or_space(flags, PUT_ZERO, (flags->field_width - 1));
		write(1, "%", 1);
	}
	else
	{
		write(1, "%", 1);
		if (flags->flag_zero == 0)
			i += fill_zero_or_space(flags, PUT_SPACE, (flags->field_width - 1));
		else
			i += fill_zero_or_space(flags, PUT_ZERO, (flags->field_width - 1));
	}
	if (flags->putlen != -1)
		flags->putlen = i + 1;
}

void	case_c(va_list *ap, t_flags *flags)
{
	char	c;
	int		i;

	c = (char)va_arg(*ap, int);
	i = 0;
	if (flags->flag_left == 0)
	{
		if (flags->flag_zero == 0)
			i += fill_zero_or_space(flags, PUT_SPACE, (flags->field_width - 1));
		else
			i += fill_zero_or_space(flags, PUT_ZERO, (flags->field_width - 1));
		write(1, &c, 1);
	}
	else
	{
		write(1, &c, 1);
		if (flags->flag_zero == 0)
			i += fill_zero_or_space(flags, PUT_SPACE, (flags->field_width - 1));
		else
			i += fill_zero_or_space(flags, PUT_ZERO, (flags->field_width - 1));
	}
	if (flags->putlen != -1)
		flags->putlen = i + 1;
}

int		fill_handle(t_flags *flags, int s_len)
{
	int		ret;
	int		len;

	ret = 0;
	len = flags->field_width - s_len;
	if (flags->flag_zero == 0)
		ret += fill_zero_or_space(flags, PUT_SPACE, len);
	else
		ret += fill_zero_or_space(flags, PUT_ZERO, len);
	return (ret);
}

void	put_s(char *str, t_flags *flags, int *i, int s_len)
{
	if (flags->flag_left == 0)
	{
		*i += fill_handle(flags, s_len);
		write(1, str, s_len);
	}
	else
	{
		write(1, str, s_len);
		*i += fill_handle(flags, s_len);
	}
	return ;
}

void	case_s(va_list *ap, t_flags *flags)
{
	char	*str;
	int		s_len;
	int		i;

	if (!(str = (char *)va_arg(*ap, char *)))
		str = "(null)";
	if ((flags->prec == 0 && flags->prec_input == 1)
			|| flags->prec_input == -1)
	{
		flags->putlen += fill_handle(flags, 0);
		return ;
	}
	if (flags->prec < 0 && flags->prec_input == 1)
		flags->prec = 0;
	s_len = (int)ft_strlen(str);
	if (flags->prec > 0 && s_len > flags->prec)
		s_len = flags->prec;
	i = 0;
	put_s(str, flags, &i, s_len);
	if (flags->putlen != -1)
		flags->putlen = i + s_len;
}
