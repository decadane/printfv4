/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:59:50 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/27 19:07:57 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putnchar(char c, size_t count)
{
	size_t		i;
	
	i = 0;
	while (i < count)
	{
		write(1, &c, 1);
		i++;
	}
	return (count);
}
