/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:03:32 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/09 14:09:06 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putwstr(wchar_t *ws)
{
	int		ws_len;
	int		wchar_len;

	if (ws == NULL)
		return (-1);
	ws_len = 0;
	while (*ws)
	{
		if ((wchar_len = ft_putwchar(*ws)) == -1)
			return (-1);
		ws_len += wchar_len;
		ws++;
	}
	return (ws_len);
}
