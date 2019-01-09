/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:58:57 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/09 14:21:01 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wstrlen(wchar_t *ws)
{
	int		ws_len;
	int		wc_len;

	if (ws == NULL)
		return (-1);
	ws_len = 0;
	while (*ws)
	{
		if ((wc_len = ft_wcharlen(*ws)) == -1)
			return (-1);
		ws_len += wc_len;
		ws++;
	}
	return (ws_len);
}
