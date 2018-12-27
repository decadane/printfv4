/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:09:13 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/27 12:49:05 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*dec(char *buf, size_t size, unsigned long long n, unsigned flag)
{
	if ((flag & SIGNED_FLAG) && (long long)n < 0)
	{
		buf[0] = '-';
		n = -(long long)n;
	}
	buf[--size] = '\0';
	while (n >= 10)
	{
		buf[--size] = n % 10 + '0';
		n /= 10;
	}
	buf[--size] = n + '0';
	if (buf[0] != 0)
	{
		if (flag & SHOWSIGN_FLAG)
			buf[0] = '+';
		else if (flag & SPACE_FLAG)
			buf[0] = ' ';
	}
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
	if (flag & HASH_FLAG)
	{
		buf[0] = '0';
		buf[1] = flag & CAPS_FLAG ? 'X' : 'x';
	}
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
	if (flag & HASH_FLAG)
		buf[0] = '0';
	return (&(buf[size]));
}

char	*itoa(t_format *fmt, unsigned long long n)
{
	char	c;
	char	*str = NULL;
	char	*tmp_str;
	char	buf[32];
	long	len;
	int		size;
	
	c = fmt->spec;
	buf[0] = 0;
	buf[1] = 0;
	buf[2] = 0;
	if (c == 'd' || c == 'i' || c == 'u')
		str = dec(buf, sizeof(buf), n, fmt->flags);
	else if (c == 'x' || c == 'X')
		str = hex(buf, sizeof(buf), n, fmt->flags);
	else if (c == 'o')
		str = oct(buf, sizeof(buf), n, fmt->flags);
	len = ft_strlen(str);
	if (fmt->precision > len)
	{
		fmt->flags &= !ZERO_FLAG;
		size = fmt->precision + (buf[0] != 0) + (buf[1] != 0);
		tmp_str = (char*)malloc(size + 1);
		if (tmp_str == NULL)
			exit(OUT_MEMORY);
		while (len >= 0)
			tmp_str[size--] = str[len--];
		while (size >= 0)
			tmp_str[size--] = '0';
		if (buf[0])
			tmp_str[0] = buf[0];
		if (buf[1])
			tmp_str[1] = buf[1];
		str = tmp_str;
	}
	else
	{
		if (buf[1])
			*(--str) = buf[1];
		if (buf[0])
			*(--str) = buf[0];
		str = ft_strdup(str);
	}
	return (str);
}
