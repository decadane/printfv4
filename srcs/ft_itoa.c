/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:01:50 by marvin            #+#    #+#             */
/*   Updated: 2019/01/10 15:21:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static unsigned long long	ft_power(int num, int power)
{
	int					i;
	unsigned long long	res;

	i = 0;
	res = 1;
	while (i < power)
	{
		res *= num;
		i++;
	}
	return (res);
}

static int					ft_count(long n)
{
	int		count;

	count = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char					ft_get_char(long n, int len)
{
	return ((n / ft_power(10, len - 1)) % 10 + '0');
}

static char					*ft_get_str(long n, int len, char *head, int is_neg)
{
	char	*result;

	result = head;
	if (is_neg)
	{
		*head = '-';
		head++;
	}
	while (len > 0)
	{
		*head = ft_get_char(n, len);
		len--;
		head++;
	}
	*head = '\0';
	return (result);
}

char						*ft_itoa(long n)
{
	int		len;
	char	*result;
	int		is_neg;

	is_neg = 0;
	len = ft_count(n);
	if (n < 0)
	{
		is_neg = 1;
		n *= -1;
		result = (char*)malloc(len + 2);
	}
	else
		result = (char*)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	return (ft_get_str(n, len, result, is_neg));
}
