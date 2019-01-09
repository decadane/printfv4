/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:38:57 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/09 14:21:58 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		ft_print_ws(t_format *f, wchar_t *ws)
{
	int		ws_len;
	int		ret_len;

	ret_len = 0;
	if (!ws)
		ws = L"(null)";
	if ((ws_len = ft_wstrlen(ws)) == -1)
		return (-1);
	if (f->flags & PRECISION && f->precision < ws_len)
	{
		ws_len = f->precision;
		ws[ws_len] = L'\0';
	}
	if (!(f->flags & LEFTFORMAT_FLAG) && f->flags & WIDTH && f->width > ws_len)
		ret_len += ft_putnchar(' ', f->width - ws_len);
	ret_len += ft_putwstr(ws);
	if ((f->flags & LEFTFORMAT_FLAG) && f->flags & WIDTH && f->width > ws_len)
		ret_len += ft_putnchar(' ', f->width - ws_len);
	return (ret_len);
}

int		ft_print_s(t_format *fmt, va_list args)
{
	char		*str;
	int			ret;
	int			len;
	char		filler;

	ret = 0;
	if (fmt->flags & L_FLAG)
		return (ft_print_ws(fmt, va_arg(args, wchar_t*)));
	str = va_arg(args, char*);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (fmt->flags & PRECISION && fmt->precision < len)
		len = fmt->precision;
	filler = (fmt->flags & ZERO_FLAG) ? '0' : ' ';
	if (!(fmt->flags & LEFTFORMAT_FLAG) && fmt->flags & WIDTH && fmt->width > len)
		ret += ft_putnchar(filler, fmt->width - (size_t)len);
	write(1, str, len);
	ret += len;
	if (fmt->flags & LEFTFORMAT_FLAG && fmt->flags & WIDTH && fmt->width > len)
		ret += ft_putnchar(filler, fmt->width - (size_t)len);
	return (ret);
}
