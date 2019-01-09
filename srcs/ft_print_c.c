/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:37:16 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/09 13:46:44 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	print_spaces(int width, unsigned flags)
{
	char	filler;
	int		len;

	len = 0;
	if (flags & WIDTH)
	{
		len = width - 1;
		filler = flags & ZERO_FLAG ? '0' : ' ';
		ft_putnchar(filler, len);
	}
	return (len);
}

static int	print_wc_spaces(int width, int wc_len)
{
	int		len;
	
	len = 0;
	if (width > wc_len)
	{
		len = width - wc_len;
		ft_putnchar(' ', len);
	}
	return (len);
}

int		ft_print_wc(t_format f, wchar_t wch)
{
	int		len;
	int		wc_len;

	len = 0;
	if ((wc_len = ft_wcharlen(wch)) == -1)
		return (-1);
	if ((f.flags & WIDTH) && !(f.flags & LEFTFORMAT_FLAG))
		len += print_wc_spaces(f.width, wc_len);
	len += ft_putwchar(wch);
	if ((f.flags & WIDTH) && (f.flags & LEFTFORMAT_FLAG))
		len += print_wc_spaces(f.width, wc_len);
	return (len);
}

int			ft_print_c(t_format f, va_list av)
{
	int		len;

	len = 0;
	if (f.flags & L_FLAG)
		return (ft_print_wc(f, va_arg(av, wchar_t)));
	if (!(f.flags & LEFTFORMAT_FLAG))
		len += print_spaces(f.width, f.flags);
	if (f.spec == '%')
		len += ft_putchar('%');
	else
		len += ft_putchar((char)va_arg(av, int));
	if (f.flags & LEFTFORMAT_FLAG)
		len += print_spaces(f.width, f.flags);
	return (len);
}
