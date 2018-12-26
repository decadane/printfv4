/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:35:47 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/20 16:15:20 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*str;

	size = ft_strlen((char*)s1);
	str = (char*)malloc(size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[size] = 0;
	while (size--)
		str[size] = s1[size];
	return (str);
}
