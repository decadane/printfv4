/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:12:54 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/09 13:34:48 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_spaces(int width, int len)
{
	if (width > len)
	{
		len = width - len;
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
		len += print_spaces(f.width, wc_len);
	len += ft_putwchar(wch);
	if ((f.flags & WIDTH) && (f.flags & LEFTFORMAT_FLAG))
		len += print_spaces(f.width, wc_len);
	return (len);
}
