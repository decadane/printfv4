/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:06:51 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/10 15:38:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include "ft_printf.h"

static void			ft_return_char(t_float *flt, t_format *lst)
{
	if (flt->sign != 0 && flt->spec_value != 1)
	{
		ft_putchar('-');
	}
	else
	{
		if (lst->flags & SHOWSIGN_FLAG && flt->spec_value != 1)
			ft_putchar('+');
		if ((lst->flags & ZERO_FLAG) && !(lst->flags & SPACE_FLAG)
				&& !flt->spec_value)
			ft_putchar('0');
		if (lst->flags & SPACE_FLAG)
			ft_putchar(' ');
	}
}

static int			ft_max(int a, int b)
{
	if (b > a)
		return (b);
	else
		return (a);
}

static long			ft_power(int base, int power)
{
	int		i;
	long	res;

	i = 0;
	res = 1;
	while (i < power)
	{
		res *= base;
		i++;
	}
	return (res);
}

static int			ft_minus_flag(char *res, t_format *lst, t_float *flt)
{
	int		l;

	lst->width = ft_max(lst->width, ft_strlen(res) + flt->sign * -1);
	l = 0;
	if (lst->flags & LEFTFORMAT_FLAG)
	{
		ft_return_char(flt, lst);
		ft_putstr(res);
		l = ft_putnchar(' ', lst->width - (ft_strlen(res) + flt->sign * -1));
	}
	else
	{
		if (lst->flags & ZERO_FLAG && !flt->spec_value)
		{
			ft_return_char(flt, lst);
			l = ft_putnchar('0', lst->width - ft_strlen(res) - flt->sign * -1);
		}
		else
		{
			l = ft_putnchar(' ', lst->width - ft_strlen(res) - flt->sign * -1);
			ft_return_char(flt, lst);
		}
		ft_putstr(res);
	}
	return (l + ft_strlen(res) + flt->sign * -1);
}

static char			*ft_return_special_cases(int flag[2], t_format *lst,
		t_float *flt)
{
	char	*res;

	res = NULL;
	if (!flag[0] && !flag[1])
	{
		flt->spec_value = 2;
		if (lst->flags & CAPS_FLAG)
			res = "INF";
		else
			res = "inf";
	}
	else if (!flag[0] && flag[1])
	{
		flt->spec_value = 1;
		if (lst->flags & CAPS_FLAG)
			res = "NAN";
		else
			res = "nan";
	}
	return (res);
}

static char			*ft_nan_inf(t_float *flt, t_format *lst)
{
	int		flag[2];
	int		i;

	i = 0;
	flag[0] = 0;
	flag[1] = 0;
	while (i < 15)
	{
		if ((flt->base >> i & 1) == 0)
			flag[0] = 1;
		i++;
	}
	i = 0;
	while (i < 63)
	{
		if ((flt->mantis >> i & 1) != 0)
			flag[1] = 1;
		i++;
	}
	return (ft_return_special_cases(flag, lst, flt));
}

static char			*ft_convert_to_str(t_float *flt, t_format *lst)
{
	char		*res;
	long		f[2];
	long double	ld;
	char		*tmp;

	ld = flt->x;
	(ld < 0) ? (ld *= -1) : 0;
	f[0] = (long)ld;
	f[1] = (long)((ld - f[0]) * (ft_power(10, lst->precision + 1)));
	(f[1] % 10 > 4) ? (f[1] = f[1] / 10 + 1) : (f[1] /= 10);
	if (f[1] == 0)
	{
		f[0]--;
		f[1] = ft_power(10, lst->precision);
	}
	if ((int)ft_strlen(ft_itoa(f[1])) > lst->precision)
	{
		f[0]++;
		tmp = (ft_itoa(f[1]));
		tmp++;
		res = ft_strjoin(ft_strjoin(ft_itoa(f[0]), "."), tmp);
	}
	else
		res = ft_strjoin(ft_strjoin(ft_itoa(f[0]), "."), ft_itoa(f[1]));
	return (res);
}

static long double	ft_read_f(t_format *lst, va_list va)
{
	long double	ld;

	if (lst->flags & L_FLAG)
		ld = va_arg(va, long double);
	else
		ld = (long double)va_arg(va, double);
	return (ld);
}

int					ft_print_f(t_format *lst, va_list va)
{
	t_float		*flt;
	char		*res;

	if (!(lst->flags & PRECISION))
		lst->precision = 6;
	flt = (t_float*)malloc(sizeof(t_float));
	flt->x = ft_read_f(lst, va);
	flt->spec_value = 0;
	res = ft_nan_inf(flt, lst);
	if (res)
		return (ft_minus_flag(res, lst, flt));
	res = ft_convert_to_str(flt, lst);
	return (ft_minus_flag(res, lst, flt));
}
