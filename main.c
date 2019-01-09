/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:27:32 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/09 14:28:05 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <wchar.h>

int		main()
{
	int		n1, n2;
	char	str[] = "|%-4S|\n";
	wchar_t	*c = L"aÃºb";

	setlocale(LC_ALL, "");
	
	ft_printbit(&c, sizeof(c));
	n1 = printf(str, c);
	n2 = ft_printf(str, c);
	printf("%d\n%d\n", n1, n2);
	
	return (0);
}
