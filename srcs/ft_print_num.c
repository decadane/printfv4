/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:14:17 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/26 17:14:20 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	cast_signed(unsigned long long *n, t_format *fmt, va_list args)
{
	if (fmt->flags & LL_FLAG)
		*n = va_arg(args, long long);
	else if (fmt->flags & L_FLAG)
		*n = va_arg(args, long);
	else if (fmt->flags & HH_FLAG)
		*n = (signed char)va_arg(args, int);
	else if (fmt->flags & H_FLAG)
		*n = (short)va_arg(args, int);
	else
		*n = va_arg(args, int);
}

static void	cast_unsigned(unsigned long long *n, t_format *fmt, va_list args)
{
	if (fmt->flags & LL_FLAG)
		*n = va_arg(args, unsigned long long);
	else if (fmt->flags & L_FLAG)
		*n = va_arg(args, unsigned long);
	else if (fmt->flags & HH_FLAG)
		*n = (unsigned char)va_arg(args, unsigned int);
	else if (fmt->flags & H_FLAG)
		*n = (unsigned short)va_arg(args, unsigned int);
	else
		*n = va_arg(args, unsigned int);
}

static char	*add_precision(char *str, unsigned precision)
{
	char				*tmp_str;
	unsigned			len;
	char				sign;
	
	sign = '0';
	len = ft_strlen(str);
	if (!(tmp_str = ft_strnew(precision)))
		exit(OUT_MEMORY);
	while (len > 0)
		tmp_str[precision--] = str[len--];
	if (str[0] == '-' || str[0] == '+')
		sign = str[0];
	else
		tmp_str[precision--] = str[0];
	while (precision > 0)
		tmp_str[precision--] = '0';
	tmp_str[0] = sign;
	return (tmp_str);
}

static void	get_string(t_format *fmt, va_list args)
{
	unsigned long long	n;

	if (fmt->spec == 'd' || fmt->spec == 'i')
	{
		fmt->flags |= SIGNED_FLAG;
		cast_signed(&n, fmt, args);
	}
	else
		cast_unsigned(&n, fmt, args);
	if (fmt->spec == 'X')
	{
		fmt->flags |= CAPS_FLAG;
		fmt->spec = 'x';
	}
	fmt->str = itoa(fmt, n);
}

int		ft_print_num(t_format *fmt, va_list args)
{
	int			ret;
	size_t		len;
	char	is_printed;

	is_printed = 0;
	get_string(fmt, args);
	len = ft_strlen(fmt->str);
	ret = len >= fmt->width ? len : fmt->width;
	if (fmt->flags & LEFTFORMAT_FLAG)
	{
		write(1, fmt->str, len);
		is_printed = 1;
		fmt->flags &= !ZERO_FLAG;
	}
	while (len < fmt->width--)
		ft_putchar(' ');
	if (!is_printed)
		write(1, fmt->str, len);
	free(fmt->str);
	return (ret);
}
