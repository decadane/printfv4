/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:37:16 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/26 18:20:58 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		ft_print_c(t_format fmt, char c)
{
	char		is_printed;
	char		filler;
	int			len;
	
	len = 1;
	is_printed = 0;
	if (fmt.flags & LEFTFORMAT_FLAG)
	{
		ft_putchar(c);
		is_printed = 1;
		fmt.flags &= !ZERO_FLAG;
	}
	filler = fmt.flags & ZERO_FLAG ? '0' : ' ';
	while (--fmt.width)
	{
		ft_putchar(filler);
		len++;
	}
	if (!is_printed)
		ft_putchar(c);
	return (len);
}
