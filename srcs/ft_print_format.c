/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:30:38 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/09 18:52:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_number(char ch)
{
	return (ch == 'd' || ch == 'u' || ch == 'o' || ch == 'x');
}

int		ft_print_format(t_format *fmt, va_list args)
{
	int		len;
	
	len = 0;
	if (fmt->spec == 'c' || fmt->spec == '%')
		len = ft_print_c(*fmt, args);
	if (fmt->spec == 's')
		len = ft_print_s(fmt, args);
	if (fmt->spec == 'p')
		len = ft_print_p(fmt, args);
	if (is_number(fmt->spec))
	{
		len = ft_print_num(fmt, args);
	}
	if (fmt->spec == 'f')
		len = ft_print_f(fmt, args);
	return (len);
}
