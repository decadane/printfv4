/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:14:17 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/27 12:33:55 by ffahey           ###   ########.fr       */
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

/*static char	*print_flag(t_format *fmt)
{
	unsigned	f;
	char		*fstr;
	
	fstr = NULL;
	f = fmt->flags;
	if (f & SIGNED_FLAG)
	{
		if (f & NEG_FLAG)
			fstr = "-";
		else if (f & SHOWSIGN_FLAG)
			fstr = "+";
		else if (f & SPACE_FLAG)
			fstr = " ";
	}
	else if (fmt->spec == 'x' && f & HASH_FLAG)
	{
		if (f & CAPS_FLAG)
			fstr = "0X";
		else
			fstr = "0x";
	}
	else if (fmt->spec == 'o' && f & HASH_FLAG)
		fstr = "0";
	return (fstr);
}
*/
int		ft_print_num(t_format *fmt, va_list args)
{
	int			ret;
	int			len;
	char	is_printed;
	char	filler;
//	char	*fstr;

	is_printed = 0;
	get_string(fmt, args);
//	fstr = print_flag(fmt);
	len = ft_strlen(fmt->str);// + ft_strlen(fstr);
	ret = len > fmt->width ? len : fmt->width;
	if (fmt->flags & LEFTFORMAT_FLAG)
	{
//		ft_putstr(fstr);
		ft_putstr(fmt->str);
		is_printed = 1;
		fmt->flags &= !ZERO_FLAG;
	}
	filler = fmt->flags & ZERO_FLAG ? '0' : ' ';
	while (len < fmt->width--)
		ft_putchar(filler);
	if (!is_printed)
	{
//		ft_putstr(fstr);
		ft_putstr(fmt->str);
	}
	free(fmt->str);
	return (ret);
}
