/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:09:13 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/26 17:11:21 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*dec(char *buf, size_t size, unsigned long long n, unsigned flag)
{
	if ((flag & SIGNED_FLAG) && (long long)n < 0)
	{
		flag &= NEG_FLAG;
		n = -(long long)n;
	}
	buf[--size] = '\0';
	while (n >= 10)
	{
		buf[--size] = n % 10 + '0';
		n /= 10;
	}
	buf[--size] = n + '0';
	return (&(buf[size]));
}

static char	*hex(char *buf, size_t size, unsigned long long n, unsigned flag)
{
	size_t	i;
	char hex_table[16];

	i = -1;
	while (++i < 10)
		hex_table[i] = i + '0';
	hex_table[i] = (flag & CAPS_FLAG) ? 'A' : 'a';
	while (++i < 16)
		hex_table[i] = hex_table[i - 1] + 1;
	buf[--size] = '\0';
	while (n >= 16)
	{
		buf[--size] = hex_table[n % 16];
		n /= 16;
	}
	buf[--size] = hex_table[n % 16];
	return (&(buf[size]));
}

static char	*oct(char *buf, size_t size, unsigned long long n, unsigned flag)
{
	(void)flag;
	buf[--size] = '\0';
	while (n >= 8)
	{
		buf[--size] = n % 8 + '0';
		n /= 8;
	}
	buf[--size] = n % 8 + '0';
	return (&(buf[size]));
}

char	*itoa(t_format *fmt, unsigned long long n)
{
	char	c;
	char	*str;
	char	*tmp_str;
	char	buf[32];
	size_t	len;
	
	c = fmt->spec;
	if (c == 'd' || c == 'i' || c == 'u')
		str = dec(buf, sizeof(buf), n, fmt->flags);
	else if (c == 'x' || c == 'X')
		str = hex(buf, sizeof(buf), n, fmt->flags);
	else if (c == 'o')
		str = oct(buf, sizeof(buf), n, fmt->flags);
	len = ft_strlen(str);
	if (fmt->precision > len)
	{
		tmp_str = ft_strnew(fmt->precision);
		if (tmp_str == NULL)
			exit(OUT_MEMORY);
		while (len >= 0)
			tmp_str[fmt->precision--] = str[len--];
		while (fmt->precision > 0)
			tmp_str[fmt->precision--] = '0';
		tmp_str[0] = '0';
		str = tmp_str;
	}
	return (str);
}
