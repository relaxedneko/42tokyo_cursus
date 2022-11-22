/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_d_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:51:06 by mabe              #+#    #+#             */
/*   Updated: 2021/01/15 20:35:32 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	left_case(t_flags *flags, long long num, int len, int *i)
{
	*i += put_minus(&num);
	*i += fill_zero_or_space(flags, PUT_ZERO, (flags->prec - len));
	put_nbr_handle(flags, num, i);
	if (*i < flags->field_width)
		*i += fill_zero_or_space(flags, PUT_SPACE, (flags->field_width - *i));
}

void	right_case(t_flags *flags, long long num, int len, int *i)
{
	int		fill_len;
	int		tmp_len;

	if (flags->prec >= len)
		tmp_len = flags->prec;
	else
		tmp_len = len;
	if (flags->field_width > flags->prec && flags->field_width > len)
	{
		if (num < 0)
			fill_len = flags->field_width - tmp_len - 1;
		else
			fill_len = flags->field_width - tmp_len;
		if (flags->flag_zero == 1 && flags->prec <= 0)
		{
			*i += put_minus(&num);
			*i += fill_zero_or_space(flags, PUT_ZERO, fill_len);
		}
		else
			*i += fill_zero_or_space(flags, PUT_SPACE, fill_len);
	}
	*i += put_minus(&num);
	if (flags->prec > len)
		*i += fill_zero_or_space(flags, PUT_ZERO, flags->prec - len);
	put_nbr_handle(flags, num, i);
}

int		check_num_zero(long long num, t_flags *flags)
{
	if (num == 0)
	{
		if (flags->prec_input == -1
				|| (flags->prec == 0 && flags->prec_input == 1))
		{
			flags->putlen = fill_zero_or_space(flags, PUT_SPACE,
					flags->field_width);
			return (1);
		}
	}
	return (0);
}

void	case_d_i_u(va_list *ap, t_flags *flags)
{
	long long	num;
	int			len;
	int			i;

	i = 0;
	if (flags->format_char == 'd' || flags->format_char == 'i')
		num = (long long)va_arg(*ap, int);
	if (flags->format_char == 'u')
		num = (long long)va_arg(*ap, unsigned int);
	if ((check_num_zero(num, flags)) == 1)
		return ;
	if (flags->prec_input == -1
			|| (flags->prec_input == 1 && flags->prec == 0))
		flags->flag_zero = 0;
	len = 0;
	put_change_num(num, "0123456789", &len, COUNT_ONLY);
	if (flags->flag_left == 1)
		left_case(flags, num, len, &i);
	else
		right_case(flags, num, len, &i);
	if (flags->putlen != -1)
		flags->putlen = i;
}

void	case_x(va_list *ap, t_flags *flags)
{
	long long	num;
	int			len;
	int			i;

	num = (long long)va_arg(*ap, unsigned int);
	if ((check_num_zero(num, flags)) == 1)
		return ;
	if (flags->prec_input == -1
			|| (flags->prec_input == 1 && flags->prec == 0))
		flags->flag_zero = 0;
	len = 0;
	put_change_num(num, "0123456789abcdef", &len, COUNT_ONLY);
	i = 0;
	if (flags->flag_left == 1)
		left_case(flags, num, len, &i);
	else
		right_case(flags, num, len, &i);
	if (flags->putlen != -1)
		flags->putlen = i;
}
