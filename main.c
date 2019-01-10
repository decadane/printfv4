/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:27:32 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/10 15:13:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <wchar.h>
#include <math.h>

int		main()
{
	int		n1, n2;
	char	str[] = "|%-4S|\n";
	wchar_t	*c = L"aÃºb";

	setlocale(LC_ALL, "");
	
	n1 = printf(str, c);
	n2 = ft_printf(str, c);
	printf("%d\n%d\n", n1, n2);

	n1 = printf("%f %F\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
	n2 = ft_printf("%f %F\n", 1444565444646.6465424242242, 1444565444646.6465424242242);

	printf("%d %d\n", n1, n2);

	return (0);
}
