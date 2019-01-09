/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:06:51 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/23 21:52:47 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <limits.h>

char	*float_to_str(long double f, int precision, char *buf, size_t size)
{
	unsigned long long	n;
	char				sign;
	size_t				i;
	char				tmp;

	sign = f < 0.0 ? 1 : 0;
	f = sign ? -f : f;
	buf[--size] = '\0';
	n = (unsigned long long)f;
	f -= (long double)n;
	i = size - precision;
	buf[i - 1] = '.';
	while (i < size)
	{
		f *= 10.0;
		buf[i++] = (int)f % 10 + '0';
		f -= (int)f;
	}
	if (f >= 0.5)
		buf[--i] += 1;
	while (buf[i] == ':')
	{
		buf[i] = '0';
		i--;
		if (buf[i] == '.')
			n++;
		else
			buf[i]++;
	}
	i = size - precision - 1;
	while (n >= 10)
	{
		buf[--i] = n % 10 + '0';
		n /= 10;
	}
	buf[--i] = n % 10 + '0';
	if (sign)
		buf[--i] = '-';
	return (&buf[i]);
}

int		main()
{
	double		f;
	char			buffer[60];
	char			*res_str;

	f = -0.;
	res_str = float_to_str(f, 10, buffer, sizeof(buffer));
	
	printf("%.10lf\n", f);
	printf("%s\n", res_str);
	return (0);
}
