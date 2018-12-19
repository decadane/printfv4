/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:30:38 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/19 19:31:00 by ffahey           ###   ########.fr       */
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
	if (fmt->spec == 'c')
		len = ft_print_c(*fmt, (char)va_arg(args, int));
	if (fmt->spec == 's')
		len = ft_print_s(*fmt, va_arg(args, char*));
//	if (is_number(fmt->spec))
//		ft_printf_num(format, args);
	return (len);
}
