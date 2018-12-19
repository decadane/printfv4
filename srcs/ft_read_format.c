/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:26:19 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/19 15:54:39 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_specificator(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'o' || 
			c == 'x' || c == 'X' || c == 'c' || c == 's' || c == 'p');
}

static unsigned	read_flag(char ch, unsigned flags, unsigned *form_number)
{
	if (ch == 'h')
		return ((flags & H_FLAG) ? HH_FLAG : H_FLAG);
	if (ch == 'l')
		return ((flags & L_FLAG) ? LL_FLAG : L_FLAG);
	if (ch == '-')
		return (LEFTFORMAT_FLAG);
	if (ch == '+')
		return (SHOWSIGN_FLAG);
	if (ch == '#')
		return (HASH_FLAG);
	if (ch >= '0' && ch <= '9')
	{
		if (ch == '0' && *form_number == 0)
			return (ZERO_FLAG);
		*form_number *= 10;
		*form_number += ch - '0';
		return (flags);
	}
	return (ERROR_FLAG);
}

int				ft_read_format(const char *fmt, t_format *format)
{
	int		i;

	i = 1;
	while (fmt[i] != '\0')
	{
		if (is_specificator(fmt[i]))
		{
			format->spec = fmt[i++];
			return(i);
		}
		format->flags |= read_flag(fmt[i], format->flags, &(format->width));
		if (format->flags & ERROR_FLAG)
			exit(WRONG_SYMBOL);
		i++;
	}
	return (i);
}
