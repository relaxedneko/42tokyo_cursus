/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:39:44 by mabe              #+#    #+#             */
/*   Updated: 2021/01/08 16:01:05 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_default_flags(t_flags *flags)
{
	flags->flag_left = 0;
	flags->flag_zero = 0;
	flags->field_width = 0;
	flags->prec = 0;
	flags->prec_input = 0;
	flags->format_char = 0;
	flags->putlen = 0;
}

void	format_char_handle(va_list *ap, t_flags *flags)
{
	if (flags->format_char == 'c')
		case_c(ap, flags);
	if (flags->format_char == 's')
		case_s(ap, flags);
	if (flags->format_char == 'd' || flags->format_char == 'i' ||
		flags->format_char == 'u')
		case_d_i_u(ap, flags);
	if (flags->format_char == 'p')
		case_p(ap, flags);
	if (flags->format_char == 'x' || flags->format_char == 'X')
		case_x(ap, flags);
	if (flags->format_char == '%')
		case_percent_sign(flags);
}

int		flag_case_handle(va_list *ap, const char **format, int len)
{
	t_flags flags;

	set_default_flags(&flags);
	*format += catch_flags(&flags, *format);
	*format += catch_width(ap, &flags, *format);
	if (**format == '.')
	{
		*format += 1;
		catch_prec(ap, &flags, &format, &len);
		if (flags.prec_input == 0 && flags.putlen != 0)
			return (flags.putlen == -1 ? -1 : len + flags.putlen);
	}
	if (flags.field_width >= INT_MAX || flags.prec >= INT_MAX)
		return (-1);
	if (**format == 'c' || **format == 's' || **format == 'p' || **format == 'd'
	|| **format == 'i' || **format == 'u' || **format == 'x' || **format == 'X'
	|| **format == '%')
	{
		flags.format_char = **format;
		*format += 1;
	}
	format_char_handle(ap, &flags);
	return (flags.putlen == -1 ? -1 : len + flags.putlen);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if ((len = flag_case_handle(&ap, &format, len)) == -1)
				return (-1);
		}
		else
		{
			write(1, format++, 1);
			len++;
		}
	}
	va_end(ap);
	return (len);
}
