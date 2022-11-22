/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabe <mabe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:43:05 by mabe              #+#    #+#             */
/*   Updated: 2021/01/14 11:57:15 by mabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

# define PUT_SPACE 1
# define PUT_ZERO 0
# define PUT_NUM 1
# define COUNT_ONLY 0

typedef struct	s_flags
{
	int			flag_left;
	int			flag_zero;
	int			field_width;
	int			prec;
	int			prec_input;
	char		format_char;
	int			putlen;
}				t_flags;

int				ft_printf(const char *format, ...);
int				flag_case_handle(va_list *ap, const char **format, int len);
int				catch_format(va_list ap, const char **format, int len);
void			format_char_handle(va_list *ap, t_flags *flags);
void			set_default_flags(t_flags *flags);
void			catch_prec(va_list *ap, t_flags *flags, const char ***format,
		int *len);
void			chk_prec(t_flags *flags, long long *ret);
int				catch_width(va_list *ap, t_flags *flags, const char *format);
void			asterisk_width(va_list *ap, const char *format, long long *ret,
		int *i);
int				catch_flags(t_flags *flags, const char *format);
void			case_c(va_list *ap, t_flags *flags);
void			case_s(va_list *ap, t_flags *flags);
void			put_s(char *str, t_flags *flags, int *i, int s_len);
int				fill_handle(t_flags *flags, int s_len);
void			case_d_i_u(va_list *ap, t_flags *flags);
int				check_num_zero(long long num, t_flags *flags);
void			left_case(t_flags *flags, long long num, int len, int *i);
void			right_case(t_flags *flags, long long num, int len, int *i);
void			case_p(va_list *ap, t_flags *flags);
void			case_x(va_list *ap, t_flags *flags);
void			case_percent_sign(t_flags *flags);

size_t			ft_strlen(const char *s);
int				fill_zero_or_space(t_flags *flags, int put_flag, int len);
int				put_minus(long long *num);
void			put_nbr_handle(t_flags *flags, long long num, int *len);
void			put_change_num(long long num, char *set, int *count,
	int put_flag);
#endif
