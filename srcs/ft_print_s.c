/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:38:57 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/19 20:26:32 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		ft_print_s(t_format fmt, char *str)
{
	int			ret;
	unsigned	len;
	char		is_printed;

	is_printed = 0;
	len = ft_strlen(str);
	len = len > fmt.length ? fmt.length : len;
	ret = len > fmt.width ? len : fmt.width;
	if (fmt.flags & LEFTFORMAT_FLAG)
	{
		write(1, str, len);
		is_printed = 1;
	}
	while (len < fmt.width--)
		ft_putchar(' ');
	if (!is_printed)
		write(1, str, len);
	return (ret);
}
