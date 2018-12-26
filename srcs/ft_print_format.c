/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:30:38 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/26 17:59:17 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_number(char ch)
{
	return (ch == 'd' || ch == 'i' || ch == 'u' || ch == 'o' || ch == 'x' || ch == 'X');
}

int		ft_print_format(t_format *fmt, va_list args)
{
	int		len;
	
	len = 0;
	if (fmt->spec == '%')
		len = ft_print_c(*fmt, '%');
	if (fmt->spec == 'c')
		len = ft_print_c(*fmt, (char)va_arg(args, int));
	if (fmt->spec == 's')
		len = ft_print_s(*fmt, va_arg(args, char*));
	if (fmt->spec == 'p')
		len = ft_print_p(va_arg(args, void*));
	if (is_number(fmt->spec))
	{
		len = ft_print_num(fmt, args);
	}
	return (len);
}
