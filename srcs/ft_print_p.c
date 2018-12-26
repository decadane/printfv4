/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:44:39 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/25 12:43:53 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		ft_print_p(void *ptr)
{
	unsigned long	num;
	unsigned char	tmp;
	char			str[20];
	size_t			i;

	i = 20;
	str[--i] = 0;
	num = (unsigned long)ptr;
	while (num)
	{
		tmp = num % 16;
		num /= 16;
		if (tmp > 9)
			str[--i] = 'a' + tmp % 10;
		else
			str[--i] = '0' + tmp;
	}
	ft_putstr("0x");
	ft_putstr(str + i);
	return (ft_strlen(str + i) + 2);
}
