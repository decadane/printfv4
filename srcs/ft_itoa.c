/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:09:13 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/18 21:40:53 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ptintf.h"

static char	*dec(char *buf, size_t size, unsigned long long n, unsigned flag)
{
	char	is_neg;

	if ((flag & SIGNED_FLAG) && (is_neg = (long long)n < 0))
		n = -(long long)n;
	buf[--size] = '\0';
	while (n >= 10)
	{
		buf[--size] = n % 10 + '0';
		n /= base;
	}
	buf[--size] = n + '0';
	if (is_neg)
		buf[--size] = '-';
	else if (flag & SIGN_FLAG)
		buf[--size] = '+';
	return (&(buf[size]));
}

static char	*hex(char *buf, size_t size, unsigned long long n, unsigned flag)
{
	size_t	i;
	const char hex_table[16];

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
	buf[--size] = '\0';
	while (n >= 8)
	{
		buf[--size] = n % 8 + '0';
		n /= 8;
	}
	buf[--size] = n % 8 + '0';
	return (&(buf[size]));
}

char	*select_number(char c, unsigned flag, unsigned long long n)
{
	char	*str;
	char	buf[32];
	
	base = 10;
	str = NULL;
	if (c == 'x' || c == 'X')
	{
		if (c == 'X')
			flag |= CAPS_FLAG;
		str = hex(buf, sizeof(buf), n, flag);
	{
	else if (c == 'u')
		str = dec(buf, sizeof(buf), n, flag);
	else if (c == 'o')
		str = oct(n, 8, flag);
	else if (c == 'd' || c == 'i')
	{
		flag |= SIGNED_FLAG;
		str = dec(buf, sizeof(buf), n, flag);
	}
}
