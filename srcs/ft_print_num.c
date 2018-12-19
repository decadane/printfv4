/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:14:17 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/19 17:54:47 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	cast_n(


void	ft_print_num(t_format fmt, va_list args)
{
	unsigned long long	n;
	char				c;
	char				sign;

	c = fmt->spec;
	if (c == 'd' || c == 'i')
	{
		fmt->flags |= SIGNED_FLAG;
		if (fmt->flags & LL_FLAG)
			n = va_arg(args, long long);
		else if (fmt->flags & L_FLAG)
			n = va_arg(args, long);
		else if (fmt->flags & HH_FLAG)
			n = (signed char)va_arg(args, int);
		else if (fmt->flags & H_FLAG)
			n = (short)va_arg(args, int);
		else
			n = va_arg(args, int);
	}
	if (c == 'u')

	fmt->str = itoa(n, fmt->flags);
}
	
