/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:26:19 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/10 14:49:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_specificator(char c)
{
	char	*str; 

	str = SPECIFICATOR;
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

static unsigned	read_flag(char ch, unsigned flags)
{
	if (ch == 'h') 
		return ((flags & H_FLAG) ? HH_FLAG : H_FLAG);
	if (ch == 'l')
		return ((flags & L_FLAG) ? LL_FLAG : L_FLAG);
	if (ch == 'z')
		return (Z_FLAG);
	if (ch == 'j')
		return (J_FLAG);
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

static int	read_number(const char *fmt, int *num)
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

static void	read_specificator(char c, t_format *f)
{
	if (c == 'X' || c == 'F')
	{
		f->flags |= CAPS_FLAG;
		f->spec = c + 32;
	}
	else if (c == 'C' || c == 'S' || c == 'D' || c == 'O' || c == 'U')
	{
		f->flags |= L_FLAG;
		f->spec = c + 32;
	}
	else if (c == 'i')
		f->spec = 'd';
	else
		f->spec = c;
	if ((f->flags & PRECISION || f->flags & LEFTFORMAT_FLAG) && c != 'f'
				&& c != 'F')
		f->flags &= ~ZERO_FLAG;
}

int		ft_read_format(const char *fmt, t_format *format)
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
		{
			format->flags |= WIDTH;
			i += read_number(fmt + i, &(format->width));
		}
		if (fmt[i] == '.')
		{
			format->flags |= PRECISION;
			i++;
			i += read_number(fmt + i, &(format->precision));
		}
		if (is_specificator(fmt[i]))
		{
			read_specificator(fmt[i++], format);
			break;
		}
		if (offset == i)
			break;
		offset = i;
	}
	return (i);
}
