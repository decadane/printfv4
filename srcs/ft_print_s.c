/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:38:57 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/26 18:40:49 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		ft_print_s(t_format fmt, char *str)
{
	int			ret;
	int			len;
	char		is_printed;
	char		filler;

	if (!str)
	{		ft_putstr("(null)");
			return (6);
	}
	is_printed = 0;
	len = ft_strlen(str);
	if (fmt.precision != 0)
		len = len > fmt.precision ? fmt.precision : len;
	ret = len > fmt.width ? len : fmt.width;
	if (fmt.flags & LEFTFORMAT_FLAG)
	{
		write(1, str, len);
		is_printed = 1;
	}
	filler = fmt.flags & ZERO_FLAG ? ' ' : '0';
	while (len < fmt.width--)
		ft_putchar(filler);
	if (!is_printed)
		write(1, str, len);
	return (ret);
}
