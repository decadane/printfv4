/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:44:39 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/18 17:23:51 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_print_p(void *ptr)
{
	unsigned long	num;
	unsigned char	tmp;
	char			str[17];
	size_t			i;

	i = 0;
	while (i < 17)
		str[i++] = 0;
	num = (unsigned long)ptr;
	while (num && i--)
	{
		tmp = num % 16;
		num /= 16;
		if (tmp > 9)
			str[i] = 'a' + tmp % 10;
		else
			str[i] = '0' + tmp;
	}
	ft_print_s("0x");
	ft_print_s(str + i);
}
