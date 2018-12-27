/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:33:26 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/27 14:50:37 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	int			ret;
	va_list		args;
	t_format	*format;
	
	ret = 0;
	va_start(args, fmt);
	while (1)
	{
		if (*fmt == '\0')
			break;
		if (*fmt == '%')
		{
			if (!(format = ft_create_format()))
				exit(-1);
			fmt += ft_read_format(fmt, format);
//			printf("spec = %c\n", format->spec);
//			printf("flags = %u\n", format->flags);
//			printf("width = %u\n", format->width);
//			printf("prec = %u\n", format->precision);
			ret += ft_print_format(format, args);
			free(format);
			continue;
		}
		write(1, fmt, 1);
		ret++;
		fmt++;
	}
	va_end(args);
	return (ret);
}
