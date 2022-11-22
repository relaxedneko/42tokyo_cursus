/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:46:58 by mabe              #+#    #+#             */
/*   Updated: 2021/01/07 15:07:49 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	case_p(va_list *ap, t_flags *flags)
{
	long long	address;
	int			i;
	int			len;

	address = (long long)va_arg(*ap, void *);
	len = 0;
	i = 0;
	if (!(address == 0 && (flags->prec_input == -1 ||
			(flags->prec == 0 && flags->prec_input == 1))))
		put_change_num(address, "0123456789abcdef", &len, COUNT_ONLY);
	if (flags->flag_left == 0)
		i += fill_zero_or_space(flags, PUT_SPACE, \
				(flags->field_width - len - 2));
	write(1, "0x", 2);
	i += 2;
	if (!(address == 0 && (flags->prec_input == -1 ||
			(flags->prec == 0 && flags->prec_input == 1))))
		put_change_num(address, "0123456789abcdef", &i, PUT_NUM);
	if (flags->flag_left == 1)
		i += fill_zero_or_space(flags, PUT_SPACE, \
				(flags->field_width - len - 2));
	if (flags->putlen != -1)
		flags->putlen = i;
}
