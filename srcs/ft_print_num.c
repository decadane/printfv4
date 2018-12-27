/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:14:17 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/27 19:50:44 by ffahey           ###   ########.fr       */
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

int		ft_print_num(t_format *fmt, va_list args)
{
	int		ret;
	unsigned long long	n;

	ret = 0;
	if (fmt->spec == 'd' || fmt->spec == 'i')
	{
		fmt->flags |= SIGNED_FLAG;
		cast_signed(&n, fmt, args);
		ret = ft_print_dec(n, fmt);
	}
	else if (fmt->spec == 'u')
	{
		cast_unsigned(&n, fmt, args);
		ret = ft_print_dec(n, fmt);
	}
	return (ret);
}
