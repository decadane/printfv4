/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:33:26 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/19 16:30:24 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_printf(const char *fmt, ...)
{
	va_list		args;
	t_format	*format;
	
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
			printf("spec = %c\n", format->spec);
			printf("flags = %u\n", format->flags);
			printf("wifth = %u\n", format->width);
			ft_print_format(format, args);
			free(format);
			continue;
		}
		write(1, fmt, 1);
		fmt++;
	}
	va_end(args);
}
