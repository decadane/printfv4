/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:37:16 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/19 18:46:34 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		ft_print_c(t_format fmt, char c)
{
	unsigned	i;
	char		is_printed;
	int			len;
	
	len = 1;
	is_printed = 0;
	if (fmt.width != 0)
	{
		len = fmt.width;
		if (fmt.flags & LEFTFORMAT_FLAG)
		{
			ft_putchar(c);
			is_printed = 1;
		}
		i = 0;
		while (i < fmt.width - 1)
		{
			ft_putchar(' ');
			i++;
		}
	}
	if (!is_printed)
		ft_putchar(c);
	return (len);
}
