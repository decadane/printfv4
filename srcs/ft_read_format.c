/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:26:19 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/25 14:34:17 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_specificator(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'o' || 
			c == 'x' || c == 'X' || c == 'c' || c == 's' || 
			c == 'p' || c == '%' || c == 'f');
}

static unsigned	read_flag(char ch, unsigned flags)
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
	if (ch == ' ')
		return (SPACE_FLAG);
	if (ch == '0')
		return (ZERO_FLAG);
	return (0); 
}

static int	read_number(const char *fmt, unsigned *num)
{
	int		i;

	i = 0;
	*num = 0;
	while (fmt[i] >= '0' && fmt[i] <= '9')
	{
		*num *= 10;
		*num += fmt[i] - '0';
		i++;
	}
	return (i);
}

int				ft_read_format(const char *fmt, t_format *format)
{
	int		offset;
	int		i;
	unsigned flag;

	i = 1;
	offset = 1;
	while (fmt[i] != '\0')
	{
		while ((flag = read_flag(fmt[i], format->flags)) != 0)
		{
			format->flags |= flag;
			i++;
		}
		if (fmt[i] > '0' && fmt[i] <= '9')
			i += read_number(fmt + i, &(format->width));
		if (fmt[i] == '.')
		{
			i++;
			i += read_number(fmt + i, &(format->precision));
		}
		if (is_specificator(fmt[i]))
		{
			format->spec = fmt[i++];
			break;
		}
		if (offset == i)
			break;
		offset = i;
	}
	return (i);
}
